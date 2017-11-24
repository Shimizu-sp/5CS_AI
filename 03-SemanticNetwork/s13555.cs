using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Network
{
    class Creature
    {
        public string breath = "yes";
    }

    class Bird : Creature
    {
        public string Tsubasa = "yes";

    }
    class parrot : Bird
    {
        public string Skill = "モノマネ";
    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("1:オウムは呼吸するか？");
            Console.WriteLine("2:オウムの特技は？");
            Console.WriteLine("1か2を入力してください。");

            Bird c1 = new Bird();

            string str = Console.ReadLine();
            if (str == "1")
            {
                Console.WriteLine(c1.breath);
            }

            parrot c2 = new parrot();

            if (str == "2")
            {
                Console.WriteLine(c2.Skill);
            }


        }
    }
}