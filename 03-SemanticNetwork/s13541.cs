using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{

    class seibutsu //生物のくくりクラス
    {
        
        public string has1;
    }

    class tori : seibutsu　// 生物に鳥は含まれるクラス
    {
        public string toriname;
        public string has2;
    }
    class oumu : tori // オ-ムは鳥に含まれるクラス
    {
        public string tokugi;
    }

    class Program
    {
        static void Main(string[] args)//main
        {
    int i;
    string s1 = "オームの特技は何ですか";
    string s2 = "オームは呼吸するか";
    string s3 = "exit";
    string s4 = "呼吸する";

          oumu p1 = new oumu();
          p1.toriname = "オ-ム"; 
          p1.tokugi = "モノマネである";
          p1.has1 = "呼吸する";
          p1.has2 = "翼がある";

        while(true){
            Console.WriteLine("終了 = exit");
            string str = Console.ReadLine();

            if (str == s1) {
                Console.WriteLine(p1.tokugi);
            }
            if (str == s2)
            {
 
                if (p1.toriname == s4)
                {
                    Console.WriteLine("yes");
                }
                if (p1.tokugi == s4)
                {
                    Console.WriteLine("yes");
                }
                if (p1.has2 == s4)
                {
                    Console.WriteLine("yes");
                }
                if (p1.has1 == s4)
                {
                    Console.WriteLine("yes");
                }

            }
            if (str == s3) {
                break;
            }
        }
        
        }
    }
}
