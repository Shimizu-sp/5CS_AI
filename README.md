# このリポジトリについて

ここはサレジオ高専情報工学科5年生後期科目である人工知能IIの課題と学生達のプログラムを公開するリポジトリです．

## 授業内容
1. 前期で習った人工知能のアルゴリズムをプログラムで実装し，そのレポート提出する
2. 実装アルゴリズムは，問題の状態空間表現（A*アルゴリズム），プロダクションシステム，意味ネットワーク，画像処理，遺伝的アルゴリズムの5種類
3. 言語：C，C++，C#，Java，ruby，Python
4. レポート提出について
* ファイル形式：PDF（pdf以外は受け取りません）
* レポート内容
    * アルゴリズムの説明（フローチャート等を用いて説明）
    * ソースコード（適宜、コメントを入れる）
    * プログラムの実行結果（実行環境，バージョン等を含む）＋課題ごとに指示がある内容を必ず示すこと
5. 授業スケジュールと各アルゴリズムのレポート提出期限は以下の通り
## 授業スケジュールとレポート提出期限

| 回数   | 日付  | 内容                | 備考 |
|:------|:------|:-------------------|:----|
| 01回目 | 09/22 | 授業ガイダンス             | |
| 02回目 | 09/29 | 問題の状態空間表現(1)       | |
| 03回目 | 10/06 | 問題の状態空間表現(2) | 13日0時課題締切 |
| 04回目 | 10/13 | プロダクションシステム(1) | |
| 05回目 | 10/20 | プロダクションシステム(2) | 27日0時課題締切 |
| 06回目 | 10/27 | 意味ネットワーク(1) | |
| 07回目 | 11/17 | 意味ネットワーク(2) | 18日0時課題締切 |
| 08回目 | 11/25 | 中間評価の説明＋期末評価までの課題説明 | 科目別補講日 |
| 09回目 | 12/01 | メディアの知識処理（画像処理）(1) | |
| 10回目 | 12/08 | メディアの知識処理（画像処理）(2) | |
| 11回目 | 12/15 | メディアの知識処理（画像処理）(3) | 5日0日課題締切 |
| 12回目 | 01/05 | 遺伝的アルゴリズム(1) | |
| 13回目 | 01/12 | 遺伝的アルゴリズム(2) | |
| 14回目 | 01/19 | 遺伝的アルゴリズム(3) | 26日0時課題締切 |
| 15回目 | 02/02 | 学習のまとめ＋期末評価の説明 | |

## 課題内容

### 01-問題の状態空間表現

#### 課題内容
下図に示す３×３のパズルに対し，初期状態をゴール状態にするプログラムをA*アルゴリズムを用いて作成する．なお，パズルにおいては，空欄の位置にあるパズルの上下左右にあるマスのみ空欄と交換可能であるとする．

（後日画像を入れる）

なお，A*アルゴリズムにおいては，発見的関数
<img src="https://latex.codecogs.com/svg.latex?f(p)=g(p)&plus;h(p)"/>
において，
<img src="https://latex.codecogs.com/svg.latex?g(p)"/>
は初期状態から現在の状態
<img src="https://latex.codecogs.com/svg.latex?p"/>
までのスライド回数，
<img src="https://latex.codecogs.com/svg.latex?h(p)"/>
は現在状態
<img src="https://latex.codecogs.com/svg.latex?p"/>
から目標位置までのマンハッタン距離の総和とする．マンハッタン距離は，1から8の数字までを計算するものとする．

#### レポートについて
1. アルゴリズムの説明
2. ソースコード
3. プログラムの実行結果
    - パズルの状態が変更するたびに，パズルの状態と発見的関数の値をファイルに出力する
    - 発見的関数の値の推移をグラフで示せ

### 02-プロダクションシステム

#### 課題内容
11種類からなる文字列「a*b-cd/e+fg」に対し，隣接する文字列の交換を繰り返すことによって「gfedcba+-*/」に並び変えるプロダクションシステムを作成する．

#### レポートについて
1. アルゴリズムの説明
    - 設計した文字列交換のルール（PM）を記述せよ
2. ソースコード
3. プログラムの実行結果
    - ルールの適用によってWM（ワーキングメモリ）の状態の変化についても出力せよ

### 03-意味ネットワーク

#### 課題内容
以下の知識からなる意味ネットワークを構築せよ．プログラム上の実現方法は，配列・ポインタ・クラス等，自身の使い易いものを選択して構わない．
* 鳥は生物である
* オームは鳥である
* 生物は呼吸する
* 鳥には翼がある
* オームの特技はモノマネである

#### レポートについて
1. アルゴリズムの説明
2. ソースコード（言語：C,C++,C#,java,ruby,python，適宜，コメントを入れる）
3. プログラムの実行結果（実行環境やバージョン等を含む）
    - 「オームの特技は何ですか」と質問し，「モノマネ」と返答する結果を提示せよ
    - 「オームは呼吸するか」と質問し，is-a関係を用いて「Yes」と返答することを提示せよ．また，is-a関係で継承関係を辿るプロセスについても出力できるようにする

### 04-メディアの知識処理（画像処理）

#### 課題内容
画像とテンプレート（画像）のファイルを読み込み，画像からテンプレートに合致するものを最低１つ抽出するプログラムを作成する．結果は，テンプレートとマッチングできた際の画像中の左上の座標（x,y）とする．近傍で複数存在する場合には，最も左上の座標とする．

なお，画像は以下の画像１と画像２であり（共に512ｘ512画素），テンプレート画像（200ｘ200画素）共に指定の場所においてある．BMP画像とデータをテキスト（3Byte/画素）に落としたもので，どちらを使ってもかまわない．
（画像ファイル：img_n.bmp, Timg_n.bmp テキストファイル：img_datan, Timg_datan n=1,2）
* 画像１：白黒２値からなる画像
* 画像２：グレースケールの画像

#### 画像について
- 元画像：img_n.bmp
- テンプレート画像：Timg_n.bmp
- 元画像テキストデータ：img_data_n.txt
- テンプレート画像テキストデータ：Timg_data_n.txt

（n=1：白黒２値からなる画像，n=2：グレースケールの画像）

**ファイル名一覧表**
|                 | 元画像     | テンプレート画像 | 元画像テキストデータ | テンプレート画像テキストデータ |
|:---------------:|:---------:|:-:|:-:|:-:|
| 白黒2値画像       | img_1.bmp | Timg_1.bmp | img_data_1.txt | Timg_data_1.txt |
| グレースケール画像 | img_2.bmp | Timg_2.bmp | img_data_2.txt | Timg_data_2.txt |

**画像仕様**
| 画像 | size | 画素値 |
|:---:|:-----:|:-----:|
| img_1.bmp | 512x512 | 0 or 255の2値 |
| Timg_1.bmp | 200x200 | 0 or 255の2値 |
| img_2.bmp | 512x512 | 0〜255 |
| Timg_2.bmp | 216x136 | 0〜255 |

- テキストデータの場合は，1画素に対し3バイト分の情報のみ
- (R=G=Bのため，1種類のみもつ)

#### レポートについて
1. アルゴリズムの説明
    - テンプレートと合致するものを見つける際に，どのような手法（テンプレートとの類似度判定基準など）で行ったかについて記述する
    - 画像１，２で異なった手法の場合にはそれぞれ記述する
2. ソースコード（言語：C,C++,C#,java,ruby,python，適宜，コメントを入れる）
3. プログラムの実行結果（実行環境やバージョン等を含む）
    - テンプレートと合致した領域の左上座標（x,y）を表示

### 05-遺伝的アルゴリズム

#### 課題内容について
- 下記関数に対し，
<img src="https://latex.codecogs.com/svg.latex?x\in[-10,15]"/>
における最大値を遺伝的アルゴリズムを用いて小数点第2位まで求める．
- 遺伝的アルゴリズムは0と1からなる10桁の数値とし，選択，交叉および突然変異を繰り返して次の世代を構成する
- 世代生成のルールは以下とする
    - 初期の遺伝子は乱数で20個生成し，以降の操作でも常に20個（交叉時は10ペア）生成する
    - 選択では上位10個はエリート選択，下位10個はルーレット選択とする
    - 交叉は1点交叉とし，中央の位置で交叉し，20個の親から20個の子を生成する
    - 突然変異は全体の5%に対し，10桁のうちの1桁分の数値が変化するものとする
    - 500世代まで実施する

<img src="https://latex.codecogs.com/svg.latex?f(x)&space;=&space;\sin&space;\frac{x&space;\pi}{7}&space;\times&space;\frac{4&space;\log_2(x&space;&plus;&space;15)}{x&plus;15}&space;&plus;&space;0.35&space;\sqrt{x&space;&plus;&space;8.5}"/>

#### レポートについて
1. アルゴリズムの説明
    - 遺伝的アルゴリズムにおける世代生成処理の流れ
    - ルーレット選択での選択方法（適応度をどのように確率に変換したか）
2. ソースコード（言語：C,C++,C#,java,ruby,python，適宜，コメントを入れる）
3. プログラムの実行結果（実行環境やバージョン等を含む）
    - 500世代実施後の最大値をもたらすxの値と最大値
    - 500世代全体を通しての最大値をもたらすxの値と最大値