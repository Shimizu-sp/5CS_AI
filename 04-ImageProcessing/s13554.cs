//////////////////////////////ここからC#プログラムです
using System;
using System.IO;

class MainClass
{
  public static void Main(string[] args)
  {
    //白黒画像に対しての処理
    int OriginW_1 = 512;
    int TempW_1 = 200;
    int TempW60_1 = 120;
    int[,] Origin_1 = new int[OriginW_1,OriginW_1];
    int[,] Template_1 = new int[TempW_1,TempW_1];
    int[,] Temp60per_1 = new int[TempW60_1,TempW60_1];
    int i = 0,j = 0;

    using(StreamReader r = new StreamReader(@"images/img_data_1.txt"))//テキストデータの読み込み
    {
      string textdata = r.ReadLine();
      string[] line = new string[OriginW_1];
      for(i = 0;i < OriginW_1;i++)
      {
        line[i] = textdata.Substring(i*(OriginW_1 * 3),(OriginW_1 * 3));
        for(j = 0;j < OriginW_1;j++)
        {
          string num = line[i].Substring(j*3,3);
          Origin_1[i,j] = int.Parse(num);
        }
      }
    }
    using(StreamReader r = new StreamReader(@"images/Timg_data_1.txt"))//テキストデータの読み込み
    {
      string textdata = r.ReadLine();
      string[] line = new string[TempW_1];
      for(i = 0;i < TempW_1;i++)
      {
        line[i] = textdata.Substring(i*(TempW_1 * 3),(TempW_1 * 3));
        for(j = 0;j < TempW_1;j++)
        {
          string num = line[i].Substring(j*3,3);
          Template_1[i,j] = int.Parse(num);
        }
      }
    }

    using(StreamReader r = new StreamReader(@"textimage/Timg_1.txt"))//テキストデータの読み込み
    {
      for(i = 0;i < TempW60_1;i++)
      {
        string line = r.ReadLine();
        for(j = 0;j < TempW60_1;j++)
        {
          string num = line.Substring(j*3,3);
          Temp60per_1[i,j] = int.Parse(num);
        }
      }
    }
    Console.WriteLine("〜〜〜〜〜〜〜課題画像1枚目〜〜〜〜〜〜〜");
    Console.WriteLine("0度回転");
    Matching(Origin_1,Template_1,1);
    Console.WriteLine();

    Console.WriteLine("時計回り90度回転");
    var rotated_1 = Rotate(Template_1);
    Matching(Origin_1,rotated_1,1);
    Console.WriteLine();

    Console.WriteLine("時計回り180度回転");
    rotated_1 = Rotate(rotated_1);
    Matching(Origin_1,rotated_1,1);
    Console.WriteLine();

    Console.WriteLine("時計回り270度回転");
    rotated_1 = Rotate(rotated_1);
    Matching(Origin_1,rotated_1,1);
    Console.WriteLine();

    Console.WriteLine("60％サイズのテンプレート ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    Console.WriteLine("0度回転");
    Matching(Origin_1,Temp60per_1,1);
    Console.WriteLine();

    Console.WriteLine("時計回り90度回転");
    var rotated60_1 = Rotate(Temp60per_1);
    Matching(Origin_1,rotated60_1,1);
    Console.WriteLine();

    Console.WriteLine("時計回り180度回転");
    rotated60_1 = Rotate(rotated60_1);
    Matching(Origin_1,rotated60_1,1);
    Console.WriteLine();

    Console.WriteLine("時計回り270度回転");
    rotated60_1 = Rotate(rotated60_1);
    Matching(Origin_1,rotated60_1,1);
    Console.WriteLine();

    //グレースケール画像に対しての処理
    int OriginW_2 = 512;
    int TempW_2 = 215;
    int TempH_2 = 136;
    int TempW50_2 = 108;
    int TempH50_2 = 68;
    int[,] Origin_2 = new int[OriginW_2,OriginW_2];
    int[,] Template_2 = new int[TempH_2,TempW_2];
    int[,] Temp50per_2 = new int[TempH50_2,TempW50_2];
    using(StreamReader r = new StreamReader(@"images/img_data_2.txt"))//テキストデータの読み込み
    {
      string textdata = r.ReadLine();
      string[] line = new string[OriginW_2];
      for(i = 0;i < OriginW_2;i++)
      {
        line[i] = textdata.Substring(i*(OriginW_2 * 3),(OriginW_2 * 3));
        for(j = 0;j < OriginW_2;j++)
        {
          string num = line[i].Substring(j*3,3);
          Origin_2[i,j] = int.Parse(num);
        }
      }
    }

    using(StreamReader r = new StreamReader(@"images/Timg_data_2.txt"))//テキストデータの読み込み
    {
      string textdata = r.ReadLine();
      string[] line = new string[TempH_2];
      for(i = 0;i < TempH_2;i++)
      {
        line[i] = textdata.Substring(i*(TempW_2 * 3),(TempW_2 * 3));
        for(j = 0;j < TempW_2;j++)
        {

          string num = line[i].Substring(j*3,3);
          Template_2[i,j] = int.Parse(num);
        }
      }
    }
    using(StreamReader r = new StreamReader(@"textimage/Timg_2.txt"))//テキストデータの読み込み
    {
      for(i = 0;i < TempH50_2;i++)
      {
        string line = r.ReadLine();
        for(j = 0;j < TempW50_2;j++)
        {
          string num = line.Substring(j*3,3);
          Temp50per_2[i,j] = int.Parse(num);
        }
      }
    }
    Console.WriteLine("〜〜〜〜〜〜〜課題画像2枚目〜〜〜〜〜〜〜");
    Console.WriteLine("0度回転");
    Matching(Origin_2,Template_2,2);
    Console.WriteLine();

    Console.WriteLine("時計回り90度回転");
    var rotated_2 = Rotate(Template_2);
    Matching(Origin_2,rotated_2,2);
    Console.WriteLine();

    Console.WriteLine("時計回り180度回転");
    rotated_2 = Rotate(rotated_2);
    Matching(Origin_2,rotated_2,2);
    Console.WriteLine();

    Console.WriteLine("時計回り270度回転");
    rotated_2 = Rotate(rotated_2);
    Matching(Origin_2,rotated_2,2);
    Console.WriteLine();

    Console.WriteLine("50％サイズのテンプレート ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    Console.WriteLine("0度回転");
    Matching(Origin_2,Temp50per_2,2);
    Console.WriteLine();

    Console.WriteLine("時計回り90度回転");
    var rotated50_2 = Rotate(Temp50per_2);
    Matching(Origin_2,rotated50_2,2);
    Console.WriteLine();

    Console.WriteLine("時計回り180度回転");
    rotated50_2 = Rotate(rotated50_2);
    Matching(Origin_2,rotated50_2,2);
    Console.WriteLine();

    Console.WriteLine("時計回り270度回転");
    rotated50_2 = Rotate(rotated50_2);
    Matching(Origin_2,rotated50_2,2);
    Console.WriteLine();





  }
  public  static void Matching(int[,] Original ,int[,] Template,int num)//探索
  {
    int SAD = 0;//差の絶対値の和
    int miniSAD = Int32.MaxValue;//最小のSADを格納
    int min_i = new int();
    int min_j = new int();
    int i,j,k,l;
    int tmp;
    int OriLengH = Original.GetLength(0) - Template.GetLength(0);
    int OriLengW = Original.GetLength(1) - Template.GetLength(1);
    int TempLengH = Template.GetLength(0);
    int TempLengW = Template.GetLength(1);
    for(i = 0;i < OriLengH; i++)
    {
      Console.CursorLeft = 0;
      Console.Write("i = " + i);
      for(j = 0; j < OriLengW; j++)
      {
        tmp = 0;
        SAD = 0;
        for(k = 0;k < TempLengH; k++)
        {
          for(l = 0;l < TempLengW;l++)
          {
            tmp = Original[i+k,j+l] - Template[k,l];//差
            SAD += Math.Abs(tmp);//絶対値の和
          }
        }
        if(miniSAD > SAD)//最小のものを格納
        {
          miniSAD = SAD;
          min_i = i;
          min_j = j;
        }
      }
    }
    if(num == 1)//白黒画像に対してマッチングしたかどうか
    {
      if(miniSAD <= 102765)
      {
        Console.WriteLine("\nminisad " + miniSAD);
        Console.WriteLine("x = " + min_j + " y = " + min_i);
      }
      else
      {
        Console.WriteLine("\nNo Matching");
      }
    }
    else if(num == 2)//グレースケール画像に対してマッチングしたかどうか
    {
      if(miniSAD <= 6692)
      {
        Console.WriteLine("\nminisad " + miniSAD);
        Console.WriteLine("x = " + min_j + " y = " + min_i);
      }
      else
      {
        Console.WriteLine("\nNo Matching");
      }
    }

  }
  public static int[,] Rotate(int[,] array)  //時計回り処理
  {
    int[,] rotatearray = new int[array.GetLength(1),array.GetLength(0)];


    for (int i = 0; i < array.GetLength(1);i++)
    {
      for (int j = 0;j < array.GetLength(0);j++)
      {
        rotatearray[i,j] = array[array.GetLength(0)-1-j,i];
      }
    }
    return rotatearray;
  }
}
