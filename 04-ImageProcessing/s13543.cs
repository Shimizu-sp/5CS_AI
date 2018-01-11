
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        public const int MAX1_X1 = 512;//512*512(画素数)
        public const int MAX1= 262144;//512*512(画素数)
        public const int T_MAX1_X1 = 200;//512*512(画素数)
        public const int T_MAX1 = 40000;//200*200(画素数)
        static void Main(string[] args)
        {
            System.IO.StreamReader sr = new System.IO.StreamReader(
            @"images/img_data_1.txt", System.Text.Encoding.GetEncoding("shift_jis"));

            
            string Text_data1 = sr.ReadToEnd();
            //Console.WriteLine(Text);
            int i = 0;
            int j = 0;
            int b = 1;
            int f = 0;
            int f2 = 0;
            string[] Text = new string[MAX1];
            string[] Text3 = new string[MAX1_X1];
            for ( i = 0; i < Text_data1.Length - 1; i += 3)
            {
               
                Text[j]=Text_data1.Substring(i, 3);
                
                if (MAX1_X1 * b == j)
                {
                    
                    for (f=0;f<MAX1_X1;f++) {
                        
                        Text3[f] = Text3[f]+Text[((f2)*MAX1_X1)+f];
                      
                    }
                    b++;
                    f2++;
                    
                }
                j++;
            }
            for (i=0;i<MAX1;i++) {
              // Console.WriteLine(Text[i]);
            }
            i = 0;
            
            for (f=0;f<MAX1_X1;f++) {
                
               //Console.Write("\n"+(f+1)+"行目\n");
               //Console.Write(Text3[f]);
            }


            sr.Close();

            System.IO.StreamReader sr2 = new System.IO.StreamReader(
            @"images/Timg_data_1.txt", System.Text.Encoding.GetEncoding("shift_jis"));

            
            string Text_data2 = sr2.ReadToEnd();
 
            string[] Text2 = new string[T_MAX1];//3文字ごとに区切って入れる用
            string[] Text4 = new string[T_MAX1_X1];//1行ずつ入れていく用
            j = 0;
            b = 1;

            f2 = 0;
            for (i = 0; i < Text_data2.Length - 1; i += 3)
            {

                Text2[j] = Text_data2.Substring(i, 3);
                

                if (T_MAX1_X1*b == j)
                {
                    for (f = 0; f < T_MAX1_X1; f++)
                    {

                        Text4[f] = Text4[f] + Text2[((f2) * T_MAX1_X1) + f];

                    }
                    b++;
                    f2++;
                }
                j++;
            }
            for (i = 0; i < T_MAX1; i++)
            {
                //Console.Write(Text2[i]);
                // Console.Write(" "+i+" ");

            }
            for (f = 0; f < T_MAX1_X1; f++)
            {

               // Console.Write("\n"+(f+1)+"行目\n");
                //Console.Write(Text4[f]);
            }
            
            sr2.Close();
            
            int gyo =0;
            int ret = 0;
            int tmp = 0;
            int flag = 0;

            for (ret = 0; f < MAX1_X1; f++)
            {

                if (Text3[gyo].IndexOf(Text4[ret]) != 0)
                {
                    tmp = Text3[gyo].IndexOf(Text4[ret]);
                }
                else
                {
                    flag = 1;
                    gyo++;
                    // flag = 0;
                }

                Console.WriteLine(tmp);

            }
        }


    }
}
