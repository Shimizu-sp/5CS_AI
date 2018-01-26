using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GA
{
    class Program
    {
        public DNA[] dna;
        public DNASort[] dnaSort;
        public Oya[] oya;
        public Kodomo[] kodomo;
        static void Main(string[] args)
        {
            var Pro = new Program();//Consoleで関数を呼ぶときに必要
            Console.WriteLine("1世代目");
            Pro.CreationDNA();    //初期生成&計算

            for (int i = 1; i < 500; i++)
            {
                
                Pro.SelectDNA();    //選択
                Pro.Cross();       //交叉
                Pro.Mutation();    //突然変異  
                Pro.CalcDNA();  //計算
                Console.WriteLine("++++++++++++++++++++++++++    {0}世代目  ++++++++++++++++++++++++++", (i + 1));
            }
        }
        public void CreationDNA()
        {
            var Pro = new Program();
            double ans = 0;
            int i = 0;
            int j = 0;
          
            dna = new DNA[20];
            for (j = 0; j < 20; j++)
            {
                dna[j] = new DNA();

            }

            System.Random r;
            r = new System.Random();
            System.Threading.Thread.Sleep(300);//0.3秒停止する(正数部と小数部に同じ値が来ないようにするため)
            System.Random r2;
            r2 = new System.Random();
            string Num2;

            Console.WriteLine("            2進数       10進数");//表示

            for (i = 0; i < 20; i++)//-10～15の遺伝子を作成
            {
                Restart://ダメ遺伝子生まれ変わりの地
                int SFlag = 0;
                string StrTemp1 = "";
                string StrTemp2 = "";
                string Seisuu = "";
                string Syousuu = "";

                for (j = 0; j < 5; j++)//整数部を2進数でランダムに作成
                {
                    Seisuu = r.Next(0, 2).ToString();
                    StrTemp1 += Seisuu;
                }
                if (StrTemp1 == "10000" || StrTemp1 == "10001" || StrTemp1 == "10010" || StrTemp1 == "10011" || StrTemp1 == "10100" || StrTemp1 == "10101")//　-（15,14,13,12,11）のときやり直し
                {
                    goto Restart;

                }
                StrTemp1 += ".";
                for (j = 0; j < 5; j++)
                {
                    Syousuu = r2.Next(0, 2).ToString();
                    if (Syousuu == "1")
                    {
                        SFlag = 1;
                    }
                    StrTemp2 += Syousuu;
                }

                if (StrTemp1 == "01111." && SFlag == 1)//15＋小数点以下に1がある（15を超える）場合やり直し
                {
                    goto Restart;

                }
                if (StrTemp1 == "10110." && SFlag == 1)//-10＋小数点以下に1がある（-10.01以下）場合やり直し
                {
                    goto Restart;

                }

                String Return10 = Pro.NiishinTo10shin(StrTemp1, StrTemp2);//2進数を10進数に直して文字列に保存
                Double Return10Double = Convert.ToDouble(Return10);//ダブル型に変換
                Num2 = StrTemp1 + StrTemp2;//2進

                Return10Double = ToRoundDown(Return10Double, 2);
                dna[i].Value = Num2;


                if (Return10Double <= -8.5)
                {
                    dna[i].Ans = -10;//非数の場合論外なので答えを-10とする
                }
                else
                {
                    dna[i].Ans = Pro.FX(Return10Double);//非数にならない場合はちゃんと計算した値を代入
                }

                Console.Write(i + 1 + "個体目　");
                Console.Write(dna[i].Value);//2進数
                Console.Write("    " + Return10Double);//10進数
                Console.WriteLine("    " + dna[i].Ans);//答えの表示
            }
        }
       
        public void SelectDNA()
        {//ソートしてエリート、ルーレット選択をする
            int i = 0,j=0;
            dnaSort = new DNASort[20];
            oya = new Oya[20];
            for (i = 0; i < 20; i++) 
            {
                
                dnaSort[i] = new DNASort();
                dnaSort[i].Value = dna[i].Value;
                dnaSort[i].Ans = dna[i].Ans;
                
                

               // Console.Write(dnaSort[i].Value);
               // Console.WriteLine(" "+dnaSort[i].Ans);

                oya[i] = new Oya();
            }
            Console.WriteLine("\n////////////////以下ソート施行後////////////////\n");

            for (i = 0; i < 20; ++i)
            {
                for (j = i + 1; j < 20; ++j)
                {
                    if (dnaSort[i].Ans < dnaSort[j].Ans)
                    {
                        double tmp = dnaSort[i].Ans;
                        string tmp2 = dnaSort[i].Value;
                        dnaSort[i].Ans = dnaSort[j].Ans;
                        dnaSort[j].Ans = tmp;

                        dnaSort[i].Value = dnaSort[j].Value;
                        dnaSort[j].Value = tmp2;
                    }
                }
                Console.Write((i+1)+"個体目" +dnaSort[i].Value);
                Console.WriteLine(" " + dnaSort[i].Ans);
            }
            ///////////////////////////////////////////////ソート完了////////////////////////////////////////////
            /////////////////////以下エリート選択/////////////////////
            for (i=0;i<10;i++)
            {
                oya[i].Value1 = dnaSort[2*i].Value;//親A
                oya[i].Value2 = dnaSort[2*i+1].Value;//親B

            }
            //////////////////エリート終わり/////////////////////
            //////////////////ルーレット開始/////////////////////

                
            
            //////////////////ルーレット終わり///////////////////

            Console.WriteLine("\n////////////////以下、親の組み合わせ発表////////////////\n");
            for (i = 0; i < 10; i++)
            {
                Console.Write(oya[i].Value1 + " + ");
                Console.WriteLine(oya[i].Value2 + "  {0}組目", i + 1);
            }
            //////////////////////////////////選択おしまい～/////////////////////////////////////////
        }
        public void Cross()
        {
            ///////////////////////////交叉開始///////////////////////////////

            string seisuu ="";
            string syousuu = "";

            int i = 0;
            kodomo = new Kodomo[20];
            Console.WriteLine("\n////////////////以下、交叉後の子供発表///////////////\n");
            for(i=0;i<20;i++)
            kodomo[i] = new Kodomo();
            for (i=0;i<10;i++) {
                

                seisuu = oya[i].Value1.Substring(0, 5);
                syousuu = oya[i].Value2.Substring(6, 5);
                kodomo[2*i].Value = seisuu + "." +syousuu;
              

                seisuu = oya[i].Value2.Substring(0, 5);
                syousuu = oya[i].Value1.Substring(6, 5);
                kodomo[2*i+1].Value = seisuu +"."+ syousuu;
       

            }
            for (i = 0; i < 20; i++)
            Console.WriteLine("{1}  {0}個体目　", i+1,kodomo[i].Value);

            ///////////////////////////交叉終了///////////////////////////////
        }
        public void Mutation()
        {
            ///////////////////////////突然変異開始///////////////////////////////
            System.Random r;
            r = new System.Random();
            string tmp = "";
            int i = 0;
            Console.WriteLine("\n////////////////以下、突然変異個体の発表///////////////\n");
            for (i = 0; i < 20; i++)
            {
                int MutationPer = r.Next(100);
                if (MutationPer < 5)
                {
                    restart:
                    tmp = kodomo[i].Value.Substring(0,5)+ kodomo[i].Value.Substring(6, 5);
                    int r2 = r.Next(10);
                    string tmp2 = "";
                    tmp2 = tmp.Substring(0, r2);
                    char Mutation = tmp[r2];
                    if (Mutation == '1')
                    {
                        
                        tmp2 = tmp2+"0"+ tmp.Substring(r2+1, (9 - r2));//1を0に

                    }else if(Mutation == '0')
                    {
                        tmp2 = tmp2 + "1" + tmp.Substring(r2+1, (9 - r2));//逆
                    }
                    tmp = "";
                    if (tmp2.Substring(0,5)=="10000")//10000になるとオーバーフローするのでNG
                    {
                        goto restart;
                    }

                    tmp = tmp2.Substring(0, 5) + "." + tmp2.Substring(5,5);
                    kodomo[i].Value = tmp;
                    Console.WriteLine("\n"+ (i+1) +"回目で突然変異発生 "+kodomo[i].Value+" に書き換えられました ({0}文字目)",(r2+1));
                }
            }
            Console.WriteLine("\n////////////////////////////////////////////////////////\n");
        }
        public void CalcDNA()
        {
            Console.WriteLine("\n////////////////以下、計算後////////////////\n");
            var Pro = new Program();
            int i = 0;
            string Num2;
   
            for (i=0;i<20;i++)
            {
                string StrTemp1 = kodomo[i].Value.Substring(0,5)+".";
                string StrTemp2 = kodomo[i].Value.Substring(6, 5);

                String Return10 = Pro.NiishinTo10shin(StrTemp1, StrTemp2);//2進数を10進数に直して文字列に保存
                Double Return10Double = Convert.ToDouble(Return10);//ダブル型に変換
                Num2 = StrTemp1 + StrTemp2;//2進

                Return10Double = ToRoundDown(Return10Double, 2);
                dna[i].Value = Num2;


                if (Return10Double <= -8.5)
                {
                    dna[i].Ans = -10;//非数の場合論外なので答えを-10とする
                }
                else
                {
                    dna[i].Ans = Pro.FX(Return10Double);//非数にならない場合はちゃんと計算した値を代入
                }

                
                Console.Write(dna[i].Value);//2進数
                Console.Write("    " + "{0:f2}",Return10Double);//10進数
                Console.Write("    " + "{0:f2}",dna[i].Ans);//答えの表示
                Console.WriteLine("     "+(i + 1 )+ "個体目");
            }
        
        }
        public string NiishinTo10shin(string Seisuu, string Syousuu)
        {

            char SeisuuTmp;
            char SyousuuTmp;
            string HosuuTmp = "";
            string HosuuTmp2 = "";
            string Jusshin = "";
            double Ans = 0;
            int f = 0;
            int Flag=0;
            int Flag2 = 0;

            if (Seisuu[0] == '1')//補数処理
            {
                Flag = 1;
            }
            if (Flag == 1) {//以下反転して1を足す
                for (f = 1; f < 5; f++)
                {
                    if (Seisuu[f] == '1')
                    {
                        HosuuTmp += "0";
                    }
                    else
                    {
                        HosuuTmp += "1";
                    }
                }
                //  Console.WriteLine("反転　：　" + HosuuTmp);
                //////////////////////反転終了//////////////////////

                if (HosuuTmp[3] == '0')
                {
                    for (f = 0; f < 4; f++)
                    {
                        if (f < 3) {
                            HosuuTmp2 += HosuuTmp[f];
                        }
                        else
                        {
                            HosuuTmp2 += "1";
                        }

                    }
                } else if (HosuuTmp[2] == '0')
                {

                    for (f = 0; f < 3; f++)
                    {
                        if (f < 2)
                        {
                            HosuuTmp2 += HosuuTmp[f];
                        }
                        else
                        {
                            HosuuTmp2 += "10";
                        }

                    }
                }
                else if (HosuuTmp[1] == '0')
                {

                    for (f = 0; f < 2; f++)
                    {
                        if (f < 1)
                        {
                            HosuuTmp2 += HosuuTmp[f];
                        }
                        else
                        {
                            HosuuTmp2 += "100";
                        }

                    }
                }
                else if (HosuuTmp[0] == '0')
                {



                    HosuuTmp2 += "1000";



                } else if (HosuuTmp == "1111")
                {
                    HosuuTmp2 = "Error";//-16となり問題の範囲外なのでエラーを返す
                    Flag2 = 1;
                    Ans = 999;
                }

                //  Console.WriteLine("足す１　：　" + HosuuTmp2);
                Seisuu = "1";
                Seisuu += HosuuTmp2;

            }
            if (Flag2 == 0)
            {
                for (f = 1; f < 5; f++)//頭が0のときは普通に計算
                {

                    SeisuuTmp = Seisuu[f];

                    if (SeisuuTmp == '1')
                    {
                        if (f == 1)
                        {
                            Ans += 8;
                        }
                        if (f == 2)
                        {
                            Ans += 4;
                        }
                        if (f == 3)
                        {
                            Ans += 2;
                        }
                        if (f == 4)
                        {
                            Ans += 1;
                        }

                    }
                    else if (SeisuuTmp == '0')
                    {
                        Ans += 0;//0の時は足さない
                    }


                }
                for (f = 0; f < 5; f++)
                {
                    SyousuuTmp = Syousuu[f];
                    if (SyousuuTmp == '1')
                    {
                        if (f == 0)
                        {
                            Ans += 0.5;
                        }
                        if (f == 1)
                        {
                            Ans += 0.25;
                        }
                        if (f == 2)
                        {
                            Ans += 0.125;
                        }
                        if (f == 3)
                        {
                            Ans += 0.0625;
                        }
                        if (f == 4)
                        {
                            Ans += 0.03125;
                        }

                    }
                    else if (SyousuuTmp == '0')
                    {
                        Ans += 0;
                    }
                }
                if (Flag == 1)
                {
                    Ans = -Ans;
                }
            }

            Flag = 0;
            Flag2 = 0;
            Jusshin = Ans.ToString();
            return Jusshin;
        }
        public static double ToRoundDown(double dValue, int iDigits)
        {
            double dCoef = System.Math.Pow(10, iDigits);

            return dValue > 0 ? System.Math.Floor(dValue * dCoef) / dCoef :
                                System.Math.Ceiling(dValue * dCoef) / dCoef;
        }
        public double FX(double x)
        {
            double ans = 0;
            ans = (Math.Sin((x * Math.PI) / 7)) * (4 * Math.Log(x + 15) / (x + 15));
            ans += +(0.35 * Math.Sqrt(x + 8.5));
            ans = Math.Round(ans, 2, MidpointRounding.AwayFromZero);

            return ans;
        }
        
    }
    public  class DNA
    {
        public string Value_;
        public int Point_;
        public double Ans_;

        public string Value
        {
            get { return this.Value_; }
            set { this.Value_ = value; }
        }
        public int Point
        {
            get { return this.Point_; }
            set { this.Point_ = value; }
        }
        public double Ans
        {
            get { return this.Ans_; }
            set { this.Ans_ = value; }
        }

    }
    public class DNASort
    {
        public string Value_;
        public int Point_;
        public double Ans_;

        public string Value
        {
            get { return this.Value_; }
            set { this.Value_ = value; }
        }
        public int Point
        {
            get { return this.Point_; }
            set { this.Point_ = value; }
        }
        public double Ans
        {
            get { return this.Ans_; }
            set { this.Ans_ = value; }
        }

    }
    public class Oya
    {
        public string Value1_;
        public string Value2_;
        public int Ans_;

        public string Value1
        {
            get { return this.Value1_; }
            set { this.Value1_ = value; }
        }
        public string Value2
        {
            get { return this.Value2_; }
            set { this.Value2_ = value; }
        }    

    }
    public class Kodomo
    {
        public string Value_;
  
        public int Ans_;

        public string Value
        {
            get { return this.Value_; }
            set { this.Value_ = value; }
        }
        public int Ans
        {
            get { return this.Ans_; }
            set { this.Ans_ = value; }
        }

    }


}
