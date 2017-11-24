using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3syume
{
    class ikimono //生物クラス
    {
        public bool ikimonoclass; //生物クラスであることを確かめるメンバ変数
        public string ikimono_name; //生物の名前を入れるメンバ変数
        public bool kokyuu = true; //呼吸するかどうかを確かめるメンバ変数
    }

    class tori : ikimono　//鳥クラス(生物クラスを継承)
    {
        public string tori_name; //鳥の種類を格納するメンバ変数
        public bool tsubasa = true; //鳥に翼があるかを確かめるメンバ変数
        public string tokugi; //鳥の特技を格納するメンバ変数

    }

    class Program
    {
        static void Main(string[] args)
        {
            int select = 0; //選択肢を格納する変数
            tori t1 = new tori(); //オブジェクト作成
            
            t1.tori_name = "オウム"; //属性を付与
            t1.ikimono_name = "鳥"; //属性を付与
            t1.tokugi = "モノマネ"; //属性を付与
            t1.ikimonoclass = true; //属性を付与

            Console.WriteLine("行いたい質問を選んでください".ToString()); //選択肢を提示
            Console.WriteLine("1 : オームの特技は何ですか？".ToString());
            Console.WriteLine("2 : オームは呼吸するか？".ToString());
            select = int.Parse(System.Console.ReadLine()); //選択肢を入力

            if (select == 1) {
                Console.WriteLine("オームの特技は何ですか？".ToString());
                Console.WriteLine("オームの特技は " + t1.tokugi.ToString());
            }
            else if (select == 2)
            {
                Console.WriteLine("オームは呼吸するか？".ToString()); //is-a関係を用いた証明をする
                Console.WriteLine("まずオームは生物か？　=　" + t1.ikimonoclass.ToString());
                Console.WriteLine("生物は呼吸をするか？　=　" + t1.kokyuu.ToString());
                Console.WriteLine("よってオームは呼吸をする".ToString()); //is-a関係を用いた証明終了
            }
            else 
            {
                Console.WriteLine("エラー".ToString());
            }
        }
    }
    
}
