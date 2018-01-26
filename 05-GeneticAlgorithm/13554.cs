using System;
using System.Linq;
using System.Collections.Generic;

namespace GA
{
    class MainClass
    {
        public struct Gen//遺伝子
        {
            public bool[] gene;//遺伝子の実態
            public double fit;//式に当てはめた時の結果
            public double roulette;//ルーレット選択した際の的

        }
        public static void Main(string[] args)
        {
            Gen[] Genetic = new Gen[20];//その代の遺伝子を格納する．世代が変わるごとに上書き

            Gen MaxGen = new Gen();//もっとも優秀な遺伝子を保存する
            MaxGen.gene = new bool[10];
            MaxGen.fit = int.MinValue;


            //初期集団の生成
            for (int i = 0; i < 20; i++)
            {
                Gen data = new Gen();
                data.gene = new bool[10];

                //乱数生成
                byte[] bs = new byte[2];
                System.Security.Cryptography.RNGCryptoServiceProvider rng =
                          new System.Security.Cryptography.RNGCryptoServiceProvider();
                rng.GetBytes(bs);
                var toint = System.BitConverter.ToInt16(bs, 0);
                string str = Convert.ToString(toint, 2);//short型で得られた乱数を2進数表記で文字列化
                if (str.Length < 10)//2進数の文字列が10文字未満の時先頭に0を追加していく
                {
                    while (str.Length != 10)
                    {
                        str = str.Insert(0, "0");
                    }
                }
                str = str.Substring(str.Length - 10, 10);//10文字以上の時10文字に収まるように大きい桁を切り捨てる

                int count = 0;
                foreach (var num in str)//Gen構造体のgeneはbool型の配列で表現するため遺伝子が1の場合trueを，0の場合falseを入れる
                {
                    bool b = num == '1' ? true : false;//numが1ならtrueを0ならfalseをbに代入
                    data.gene[count] = b;
                    count++;
                }
                data.fit = Fitness(data.gene);//式に当てはめ結果を保存
                if (MaxGen.fit < data.fit)//最良の遺伝子を保存
                {
                    MaxGen.fit = data.fit;
                    data.gene.CopyTo(MaxGen.gene, 0);
                }
                Genetic[i] = data;
            }
            Console.WriteLine("___________GA____________");
			for (int i = 0; i < 500;i++)//500世代回す
			{
                Genetic = Select(Genetic);//選択

                for (int j = 0;j < 20;j+=2)//交叉
                {
                    Gen[] cross = new Gen[2];
                    cross[0].gene = new bool[10];
                    cross[1].gene = new bool[10];

                    //交叉関数に渡すためにGeneticの値をcrossに値渡しでコピー
                    Genetic[j].gene.CopyTo(cross[0].gene, 0);
                    Genetic[j+1].gene.CopyTo(cross[1].gene, 0);

                    cross = Crossover(cross[0], cross[1]);//交叉関数の呼び出し

                    //結果をGeneticに保存
                    cross[0].gene.CopyTo(Genetic[j].gene, 0);
                    cross[1].gene.CopyTo(Genetic[j+1].gene, 0);
                }
                //どの遺伝子を突然変異させるかをランダムで決定する．そのままだと似たランダム値が得られるためシード値を加えより値が散らばるようにする
                int seed = Environment.TickCount;
                Random r = new Random(seed + i);
                int rnd = r.Next(20);
                Mutation(Genetic[rnd]).gene.CopyTo(Genetic[rnd].gene,0);//突然変異

                for (int j = 0; j < 20;j++)//フィットネスの計算と初期化
                {
                    Genetic[j].fit = Fitness(Genetic[j].gene);
                    Genetic[j].roulette = 0;
                    if(MaxGen.fit < Genetic[j].fit)//最良の遺伝子を保存
                    {
                        MaxGen.fit = Genetic[j].fit;
                        Genetic[j].gene.CopyTo(MaxGen.gene, 0);
                    }
                }
            }
            Gen last = new Gen();
            last.gene = new bool[10];
            last.fit = int.MinValue;
            for (int i = 0; i < 20;i++)
            {
                if (last.fit < Genetic[i].fit)
                {
                    last.fit = Genetic[i].fit;
                    Genetic[i].gene.CopyTo(last.gene, 0);
                }
            }
            Console.WriteLine("lastGen.fit : " + last.fit);
            foreach (var n in last.gene)
                Console.Write(n == true ? "1" : "0");
            Console.WriteLine();
            Console.WriteLine(ConvertX(last.gene));

            Console.WriteLine("%%%%%%%%%%%%%%%");
            Console.WriteLine("MaxGene.fit : " + MaxGen.fit);

            foreach (var n in MaxGen.gene)
                Console.Write(n == true ? "1" : "0");
            Console.WriteLine();
            Console.WriteLine(ConvertX(MaxGen.gene));

        }

        public static Gen[] Select(Gen[] gene)//選択
        {
            var Genetic = gene.OrderByDescending(g => g.fit).ToArray();//fitの値で良い順にソート
            
            var roulette = new Gen[10];//下位10個の遺伝子を保存する用

            for (int i = 0; i < 10;i++)//Geneticからrouletteにコピー
            {
                roulette[i].fit = Genetic[i + 10].fit;
                roulette[i].gene = new bool[10];
                for (int j = 0; j < 10; j++)
                {
                    roulette[i].gene[j] = Genetic[i + 10].gene[j];
                }
            }

            
            double total = new double();
            double sumfit = new double();

            for (int i = 0; i < 10;i++)//ルーレット選択するために合計値取得
            {
                if (roulette[i].fit > 0.0)
                    total += roulette[i].fit;
            }

            for (int i = 0; i < 10;i++)//適応度の計算，マイナス値とNaNの時は0
            {
                if (roulette[i].fit > 0.0)
                {
                    sumfit += roulette[i].fit / total;//適応度は式の答え/合計値
                    roulette[i].roulette = sumfit;
                }
                else
                {
                    roulette[i].roulette = 0;//NaNやマイナス値はルーレットから除外する
                }
            }
            Random r = new Random();
            double range = new double();//一つ前の遺伝子のfitの値
            for (int i = 0; i < 10;i++)
            {
                range = 0.0;
                double rnd = r.NextDouble();//どの遺伝子を選択するかの乱数
                for (int j = 0; j < 10;j++)
                {
                    if(range <= rnd && roulette[j].roulette >= rnd)//遺伝子が選択され，コピーする
                    {
                        Genetic[i + 10].fit = roulette[j].fit;
                        Genetic[i + 10].roulette = roulette[j].roulette;
                        roulette[j].gene.CopyTo(Genetic[i+10].gene, 0);
                        break;
                    }
                    range = roulette[j].roulette;
                }
            }
            return Genetic;
        }

        public static Gen[] Crossover(Gen gen1,Gen gen2)//交叉
        {
            Gen[] ans = new Gen[2];
            ans[0].gene = new bool[10];
            ans[1].gene = new bool[10];
            for (int i = 0; i < 5;i++)//遺伝子の前半5桁を入れ替え
            {
                bool tmp = gen1.gene[i];
                gen1.gene[i] = gen2.gene[i];
                gen2.gene[i] = tmp;
            }
			
            gen1.gene.CopyTo(ans[0].gene,0);
            gen2.gene.CopyTo(ans[1].gene,0);

            return ans;
        }

        public static Gen Mutation(Gen gen)//突然変異
        {
            Gen answer = new Gen();
            answer.gene = new bool[10];
            gen.gene.CopyTo(answer.gene, 0);

            int seed = Environment.TickCount;
            Random r = new Random(seed);
            int rnd = r.Next(10);
            answer.gene[rnd] = !answer.gene[rnd];//0から9までの乱数を出しその値の桁の箇所を反転
            return answer;
        }

        public static double ConvertX(bool[] gen)//遺伝子を入力したらxの値を返す
        {
            double x = new double();
            int pow = 1;
            int num = 0;//2進数→10進数
            for (int i = 9; i >= 0;i--)//2進数を10進数に変換する
            {
                
                if (gen[i])//その桁が1の時
                {
                    num += pow; 
                }
                pow *= 2;
            }
            x = -10.0 + (double)(num) * 0.0244;//0,000,000,000の遺伝子の時をx=-10とする．1増えるたびに0.0244掛け合わせ足していく
            return x;
        }
        public static double Fitness(bool[] gen)//式に当てはめ結果を返す
        {
            double answer = new double();
            double x = ConvertX(gen);
            answer = Math.Sin((x * Math.PI) / 7) * ((4 * Math.Log(x + 15)) / (x + 15)) + (0.35 * Math.Sqrt(x + 8.5));
            return answer;
        }

    }
}
