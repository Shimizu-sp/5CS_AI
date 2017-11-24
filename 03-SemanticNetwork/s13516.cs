using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FrameNetwork2
{
    class seibutu  //生物のクラス
    {
        public string class_seibutu="yes";
        public string name_seibutu;
        public string kokyuu;
    }

    class tori : seibutu  //鳥のクラス　//生物のクラスを継ぐ
    {
        public string name_tori;
        public string tubasa="yes";
        public string tokugi;
    }


    class Program
    {
        static void Main(string[] args)
        {
            ;
            tori tori1 = new tori();

            tori1.name_tori = "オーム"; //属性を付与  //tori1の名前はオーム //鳥クラス
            tori1.name_seibutu = "鳥";  //tori1は鳥である //生物クラス
            tori1.tokugi = "モノマネ";  //tori1の特技はモノマネである //鳥クラス
            tori1.kokyuu = "する";  //tori1は呼吸する //生物クラス

            Console.Write("質問を「オームの特技は何ですか」「オームは呼吸するか」のどちらかで入力してください\n");
            Console.Write("質問は？：");
            var q = Console.ReadLine();

            if (q == "オームの特技は何ですか")  //特技をきかれたとき
            {
                Console.WriteLine(tori1.tokugi);
            }
            else if(q=="オームは呼吸するか"){  //呼吸をきかれたとき
                Console.WriteLine("オームは生物："+tori1.class_seibutu);
                Console.WriteLine("呼吸:"+tori1.kokyuu);
            }
            else  //間違った質問のとき
            {
                Console.WriteLine("質問を入力しなおしてください");
            }    
        }
    }
}
