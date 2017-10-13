using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;

namespace A_Star
{
    class MainClass
    {
        public struct Node//ノード構造体
        {
            public int[,] Table;//パズルの盤面
			public int Manhattan_Cost;//マンハッタンコスト
			public int Deep_Cost;//深さ
			public bool Currect_node;//ノードが正しいかどうか
            public string Operation;//操作手順:u(上)r(右)d(下)l(左)

			public Node(int[,] _Table,int _Manhattan_Cost,int _Deep_Cost,bool _Currect_node,string _Operation)
			{
                Table = _Table;
                Manhattan_Cost = _Manhattan_Cost;
                Deep_Cost = _Deep_Cost;
                Currect_node = _Currect_node;
                Operation = _Operation;
			}
        }
        public static void Main(string[] args)
        {
            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();//時間計測
            sw.Start();//時間計測スタート
            Node data = new Node();//初期データ用ノード

            data.Table = new int[3, 3] { { 8, 1, 5 }, { 2, 9, 4 }, { 6, 3, 7 } };//初期状態，空白パネルは9とする

            List<int[,]> All_scene = new List<int[,]>();//全ての盤面を格納するリスト

            for (int i = 0; i < 3;i++)//
            {
                for (int j = 0; j < 3;j++)
                {
                    Console.WriteLine("(" + (i + 1)  + " ," + (j + 1) + ") " +
                                      " Value = " + data.Table[i,j] + " Cost = " + Manhattan(j + 1, i + 1, data.Table[i, j]));
                    data.Manhattan_Cost += Manhattan(j + 1, i + 1, data.Table[i, j]);//初期ノードにマンハッタン距離を加算
                }
            }
            Console.WriteLine("コストの総和 : " + data.Manhattan_Cost);

            Console.WriteLine("コストのTotal :"+ Total_Manhattan(data.Table));

            data.Deep_Cost = 0;//初期の深さ

            All_scene.Add(data.Table);//初期の場面を記録

			Stack<Node> nodes = new Stack<Node>();//深さ優先探索をするためにstackを用意する
			nodes.Push(data);//根をstackに追加

            Node currentnode = new Node();
            currentnode.Table = new int[3, 3];

            int Genetic_count = 0;
            using (StreamWriter w = new StreamWriter(@"./output.txt"),graph = new StreamWriter(@"./graph.txt"))
            {
                while (nodes.Count() != 0)//探索開始〜スタックが空になるまで
                {
                    currentnode = Copy_node(nodes.Pop());//現在のノードにスタックからポップしコピー

                    List<Node> nextnode = new List<Node>();//currentnodeからできる子ノードの格納リスト

                    int bestcost = int.MaxValue;

                    for (int i = 0; i < 4; i++)//親ノードから生まれる子は最大4つ
                    {
                        nextnode.Add(GetNextNode(currentnode, i));//子ノードを取得
                        if (nextnode[i].Currect_node == false)//正しくない操作は弾く
                            continue;

                        if (isMatchScene(All_scene, nextnode[i].Table))//過去に同じ盤面があった場合弾く
                            continue;
                        
                        if (bestcost > nextnode[i].Manhattan_Cost + nextnode[i].Deep_Cost)//最良の発見的関数を取得
							bestcost = nextnode[i].Manhattan_Cost + nextnode[i].Deep_Cost;
                        
                        if (nextnode[i].Manhattan_Cost == 0)//完成した時
                        {
                            currentnode = Copy_node(nextnode[i]);//現在のノードに完成ノードをコピー
                            Console.WriteLine("Exitloop");
                            goto exitloop;//2重ループを抜ける
                        }
                    }
                    foreach (var push_node in nextnode)//得られた子ノードをstackにプッシュ
                    {
                        if (push_node.Manhattan_Cost + push_node.Deep_Cost != bestcost)//いいやつだけpush
                          continue;

                        if (push_node.Deep_Cost + Total_Manhattan(push_node.Table) > 28)//発見的関数の値を28までで制限する
                            continue;

                        All_scene.Add(push_node.Table);//スタックにプッシュする盤面を記録する

                        nodes.Push(push_node);//プッシュ
                        Console.WriteLine("発見的関数の値 : " + (push_node.Deep_Cost + Total_Manhattan(push_node.Table)));
                        w.WriteLine("発見的関数の値 : " + (push_node.Deep_Cost + Total_Manhattan(push_node.Table)));
                        Console.WriteLine("Deep : " + push_node.Deep_Cost);
                        Console.WriteLine("Manhattan" + Total_Manhattan(push_node.Table));
                        Console.WriteLine(push_node.Operation);
                        Genetic_count++;
                        graph.WriteLine(Genetic_count + " " + (push_node.Deep_Cost  + Total_Manhattan(push_node.Table)));//深さ マンハッタン
                        for (int i = 0; i < 3; i++)
                        {
                            for (int j = 0; j < 3; j++)
                            {
                                Console.Write(push_node.Table[i, j] + " ");
                                w.Write(push_node.Table[i, j] + " ");
                            }
                            Console.WriteLine();
                            w.WriteLine();
                        }
                        Console.WriteLine();
                        Console.WriteLine();
                        w.WriteLine();
                        w.WriteLine();
                    }

                }
            exitloop:;
                Console.WriteLine();
                Console.WriteLine();
                Console.WriteLine("初期盤面");
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        Console.Write(data.Table[i, j] + " ");
                    }
                    Console.WriteLine();
                }
                Console.WriteLine("最後のマンハッタン距離 = " + currentnode.Manhattan_Cost);
                Console.WriteLine("発見的関数の値 : " + (currentnode.Deep_Cost + Total_Manhattan(currentnode.Table)));
                w.WriteLine("最終発見的関数の値 : " + (currentnode.Deep_Cost + Total_Manhattan(currentnode.Table)));
                Console.WriteLine("Deep : " + currentnode.Deep_Cost);
                Console.WriteLine("Manhattan" + Total_Manhattan(currentnode.Table));
                Console.WriteLine("操作手順 " + currentnode.Operation);
                Console.WriteLine("最終盤面");
                w.WriteLine("操作手順 " + currentnode.Operation);
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        Console.Write(currentnode.Table[i, j] + " ");
                        w.Write(currentnode.Table[i, j] + " ");
                    }
                    Console.WriteLine();
                    w.WriteLine();
                }
                sw.Stop();
                Console.WriteLine(sw.Elapsed);
            }
        }

        public static Node GetNextNode(Node currentNode,int direction)
        {
			Node nextnode = new Node();
			nextnode.Table = new int[3, 3];
			nextnode.Currect_node = true;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					nextnode.Table[i, j] = currentNode.Table[i, j];//盤面だけコピー
				}
			}
            nextnode.Operation = currentNode.Operation;//操作手順のコピー

            int[] Empty_position = Find_9(currentNode.Table);//空白パネルの座標の取得

            switch(direction)//空白パネルとその上下左右の向き(direction)のパネルの入れ替え操作
            {
                case 0://上
                    if (Empty_position[0]  == 0)//上を選択すると範囲外となってしまうので正しくないノードとする
                    {
                        nextnode.Currect_node = false;
                        return nextnode;
                    }
                    try
                    {
                        if (nextnode.Operation.Substring(nextnode.Operation.Length - 1) == "d")//手順のループを防ぐ
                        {
                            nextnode.Currect_node = false;
                            return nextnode;
                        }
                    }
                    catch(System.NullReferenceException)//操作手順がないとエラーを吐いてしまう
                    {
                    }
                    //入れ替えと操作手順の追加
                    nextnode.Table[Empty_position[0],Empty_position[1]] = nextnode.Table[Empty_position[0] - 1, Empty_position[1]];
                    nextnode.Table[Empty_position[0] - 1, Empty_position[1]] = 9;
                    nextnode.Operation += "u";
                    break;

                case 1://右
                    if (Empty_position[1]  == 2)//右を選択すると範囲外となってしまうので正しくないノードとする
					{
						nextnode.Currect_node = false;
						return nextnode;
					}
					try
					{
						if (nextnode.Operation.Substring(nextnode.Operation.Length - 1) == "l")//手順のループを防ぐ
						{
                            nextnode.Currect_node = false;
							return nextnode;
						}
					}
					catch (System.NullReferenceException)
					{
					}
                    nextnode.Table[Empty_position[0], Empty_position[1]] = nextnode.Table[Empty_position[0], Empty_position[1] + 1];
                    nextnode.Table[Empty_position[0], Empty_position[1] + 1] = 9;
                    nextnode.Operation += "r";
                    break;

                case 2://下
                    if (Empty_position[0] + 1 == 3)//下を選択すると範囲外となってしまうので正しくないノードとする
					{
						nextnode.Currect_node = false;
						return nextnode;
					}
					try
					{
						if (nextnode.Operation.Substring(nextnode.Operation.Length - 1) == "u")//手順のループを防ぐ
						{
                            nextnode.Currect_node = false;
							return nextnode;
						}
					}
					catch (System.NullReferenceException)
					{
					}
                    nextnode.Table[Empty_position[0], Empty_position[1]] = nextnode.Table[Empty_position[0] + 1, Empty_position[1]];
                    nextnode.Table[Empty_position[0] + 1, Empty_position[1]] = 9;
                    nextnode.Operation += "d";
                    break;

                case 3://左
                    if (Empty_position[1] == 0)//左を選択すると範囲外となってしまうので正しくないノードとする
					{
						nextnode.Currect_node = false;
						return nextnode;
					}
					try
					{
						if (nextnode.Operation.Substring(nextnode.Operation.Length - 1) == "r")//手順のループを防ぐ
						{
                            nextnode.Currect_node = false;
							return nextnode;
						}
					}
					catch (System.NullReferenceException)
					{
					}
                    nextnode.Table[Empty_position[0], Empty_position[1]] = nextnode.Table[Empty_position[0], Empty_position[1] - 1];
                    nextnode.Table[Empty_position[0], Empty_position[1] - 1] = 9;
                    nextnode.Operation += "l";
                    break;
            }
            nextnode.Manhattan_Cost = Total_Manhattan(nextnode.Table);//マンハッタン距離の総和
            nextnode.Deep_Cost = currentNode.Deep_Cost + 1;//深さを加算
            return nextnode;
		}
        public static bool isMatchScene(List<int[,]> all_panel,int[,] current_panel)//過去の盤面と同じものがあるかどうか
        {
            int count = 0;
            for (int h = 0; h < all_panel.Count();h++)
            {
                for (int i = 0; i < 3;i++)
                {
                    for (int j = 0; j < 3;j++)
                    {
                        if (all_panel[h][i, j] == current_panel[i, j])
                        {
                            count++;
                        }
                    }
                }
                if (count == 9)//あった
                {
                    return true;
                }
                count = 0;
            }
            return false;
        }
        public static Node Copy_node(Node data)//ノードのコピー
        {
			Node node = new Node();
            node.Table = new int[3, 3];
            for (int i = 0; i < 3;i++)
            {
                for (int j = 0; j < 3;j++)
                {
                    node.Table[i, j] = data.Table[i, j];
                }
            }
		    node.Manhattan_Cost = data.Manhattan_Cost;
		    node.Deep_Cost = data.Deep_Cost;
		    node.Currect_node = data.Currect_node;
            node.Operation = data.Operation;
		    return node; 
		}
        public static int Total_Manhattan(int[,] data)//マンハッタン距離の総和
        {
            int cost = 0;
		    for (int i = 0; i < 3;i++)
		    {
		        for (int j = 0; j < 3;j++)
		        {
		            cost += Manhattan(j + 1, i + 1, data[i, j]);
		        }
		    }
            return cost;
		}
        public static int[] Find_9(int[,] data)//空白マスの座標取得
        {
            int[] answer = new int[2];
            for (int i = 0; i < 3;i++)
            {
                for (int j = 0; j < 3;j++)
                {
                    if (data[i, j] == 9)
                    {
                        answer[0] = i;
                        answer[1] = j;
                        break;
                    }
                }
            }
            return answer;
        }
        public static int Manhattan(int x,int y,int value)//マンハッタン距離を求める
        {
            int cost = 0;
            if (value == 9)//9は空白パネルなのでカウントしない
                return cost;
            //行揃え
            if(y == 1)
            {
                if(!(value >= 1 && value <= 3))//行で移動する必要がある
                {
                    if(value >= 4 && value <= 6)//1段下に移動するのでコスト＋1
                    {
                        cost += 1;
                    }
                    else if(value >= 7 && value <= 9)//2段下に移動するのでコスト＋2
                    {
                        cost += 2;
                    }
                }
            }
            else if (y == 2)
            {
                if(!(value >= 4 && value <= 6))//行で移動する必要がある
				{
                    cost += 1;//2行目から上下に移動してもコストは必ず1
                }
            }
            else if (y == 3)
            {
                if(!(value >= 7 && value <= 9))//行で移動する必要がある
				{
					if (value >= 1 && value <= 3)//2段上に移動するのでコスト＋2
					{
						cost += 2;
					}
					else if (value >= 4 && value <= 6)//1段上に移動するのでコスト＋1
					{
						cost += 1;
					} 
                }
            }
            //列揃え
            if(x == 1)
            {
                if (!(value == 1 || value == 4 || value == 7))//列で移動する必要がある
                {
                    if(value == 2 || value == 5 || value == 8)//1列右に移動するのでコスト＋1
                    {
                        cost += 1;
                    }
                    else if(value == 3 || value == 6 || value == 9)//1列右に移動するのでコスト＋2
					{
                        cost += 2;
                    }
                }
            }
            else if (x == 2)
            {
                if (!(value == 2 || value == 5 || value == 8))//列で移動する必要がある
				{
                    cost += 1;//2列目から左右に移動してもコスト＋1
                }
            }
            else if (x == 3)
            {
                if(!(value == 3 || value == 6 || value == 9))//列で移動する必要がある
				{
                    if(value == 1 || value == 4 || value == 7)//2列左に移動するのでコスト＋2
					{
                        cost += 2;
                    }
                    else if(value == 2 || value == 5 || value == 8)//1列左に移動するのでコスト＋1
					{
                        cost += 1;
                    }
                }
            }
            return cost;
        }
    }
}