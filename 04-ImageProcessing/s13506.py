import numpy as np

IMG1_HEIGHT = 512
IMG1_WIDTH = 512
IMG2_HEIGHT = 512
IMG2_WIDTH = 512

TEMPLATE1_HEIGHT = 200
TEMPLATE1_WIDTH = 200
TEMPLATE2_HEIGHT = 136
TEMPLATE2_WIDTH = 215

np.set_printoptions(threshold=np.inf)
img1 = np.zeros( (IMG1_HEIGHT, IMG1_WIDTH), dtype=int )                         # 元画像1
img2 = np.zeros( (IMG2_HEIGHT, IMG2_WIDTH), dtype=int )                         # 元画像2

template1 = np.zeros( (TEMPLATE1_HEIGHT, TEMPLATE1_WIDTH), dtype=int )          # テンプレート画像1
template1_270 = np.zeros( (TEMPLATE1_WIDTH, TEMPLATE1_HEIGHT), dtype=int )      # テンプレート画像1を270度回転

template2 = np.zeros( (TEMPLATE2_HEIGHT, TEMPLATE2_WIDTH), dtype=int )          # テンプレート画像2
template2_90 = np.zeros( (TEMPLATE2_WIDTH, TEMPLATE2_HEIGHT), dtype=int )       # テンプレート画像2を90度回転

tmp = np.zeros( (IMG1_HEIGHT - TEMPLATE1_HEIGHT, IMG1_WIDTH - TEMPLATE1_WIDTH), dtype=int )
tmp2 = np.zeros( (IMG2_HEIGHT - TEMPLATE2_HEIGHT, IMG2_WIDTH - TEMPLATE2_WIDTH), dtype=int )

if __name__ == '__main__':
    # テキストから文字列を取得
    with open('img_data_1.txt', 'r') as f:
        img1_str = f.read()

    with open('Timg_data_1.txt', 'r') as f:
        template1_str = f.read()

    with open('img_data_2.txt', 'r') as f:
        img2_str = f.read()
        
    with open('Timg_data_2.txt', 'r') as f:
        template2_str = f.read()


    # 文字列を0～255までの数値とし2次元配列に格納
    # 画像1
    for i in range( IMG1_HEIGHT ):        
        for j in range( IMG1_WIDTH ):
            img1[i][j] = int( img1_str[j * 3 + i * IMG1_HEIGHT * 3  : j * 3 + i * IMG1_HEIGHT * 3 + 3 ] )   # 3文字区切りで配列に格納

    # 画像2
    for i in range( IMG2_HEIGHT ):        
        for j in range( IMG2_WIDTH ):
            img2[i][j] = int( img2_str[j * 3 + i * IMG2_WIDTH * 3  : j * 3 + i * IMG2_WIDTH * 3 + 3 ] )
    
    # テンプレート画像1
    for i in range( TEMPLATE1_HEIGHT ):        
        for j in range( TEMPLATE1_WIDTH ):
            template1[i][j] = int( template1_str[j * 3 + i * TEMPLATE1_HEIGHT * 3  : j * 3 + i * TEMPLATE1_HEIGHT * 3 + 3 ] )

    # テンプレート画像2
    for i in range( TEMPLATE2_HEIGHT ):        
        for j in range( TEMPLATE2_WIDTH ):
            template2[i][j] = int( template2_str[j * 3 + i * TEMPLATE2_WIDTH * 3  : j * 3 + i * TEMPLATE2_WIDTH * 3 + 3 ] )

    # 回転した画像を作成
    # 270度回転画像
    for i in range( TEMPLATE1_WIDTH ):        
        for j in range( TEMPLATE1_HEIGHT ):
            template1_270[i][j] = template1[j][TEMPLATE1_HEIGHT - i - 1]

    # 90度回転画像
    for i in range( TEMPLATE2_WIDTH ):        
        for j in range( TEMPLATE2_HEIGHT ):
            template2_90[i][j] = template2[TEMPLATE2_HEIGHT - j - 1][i]
    
    print( "画像1のテンプレートマッチング" )
    # 画像1のテンプレートマッチング
    num_min = [[0,0]]
    for i in range( IMG1_HEIGHT - TEMPLATE1_HEIGHT ):        
        for j in range( IMG1_WIDTH - TEMPLATE1_WIDTH ):
            # テンプレートと同じサイズの配列を画像から取り出し減算 すべての要素を足したものを代入
            tmp[i][j] = np.sum( list( map( abs, img1[i:i+TEMPLATE1_HEIGHT, j:j+ TEMPLATE1_WIDTH] - template1 ) ) )
            if tmp[ num_min[0][0] ][ num_min[0][1] ] > tmp[i][j]:   # 値が低ければ更新
                num_min[0][0],num_min[0][1] = i,j

    print( "x={0} y={1}".format( num_min[0][1], num_min[0][0] ))

    # 画像1の270度回転画像のテンプレートマッチング
    num_min = [[0,0]]
    for i in range( IMG1_HEIGHT - TEMPLATE1_HEIGHT ):        
        for j in range( IMG1_WIDTH - TEMPLATE1_WIDTH ):
            tmp[i][j] = np.sum( list( map( abs, img1[i:i+TEMPLATE1_HEIGHT, j:j+ TEMPLATE1_WIDTH] - template1_270 ) ) )
            if tmp[ num_min[0][0] ][ num_min[0][1] ] > tmp[i][j]:
                num_min[0][0],num_min[0][1] = i,j
    
    print( "x={0} y={1}".format( num_min[0][1], num_min[0][0] ))

    print( "画像2のテンプレートマッチング" )
    # 画像2のテンプレートマッチング
    num_min = [[0,0]]
    for i in range( IMG2_HEIGHT - TEMPLATE2_HEIGHT ):        
        for j in range( IMG2_WIDTH - TEMPLATE2_WIDTH ):
            tmp2[i][j] = np.sum( list( map( abs, img2[i:i+TEMPLATE2_HEIGHT, j:j+ TEMPLATE2_WIDTH] - template2 ) ) )
            if tmp2[ num_min[0][0] ][ num_min[0][1] ] > tmp2[i][j]:
                num_min[0][0],num_min[0][1] = i,j

    print( "x={0} y={1}".format( num_min[0][1], num_min[0][0] ))

    # 画像2の90度回転画像のテンプレートマッチング
    num_min = [[0,0]]
    for i in range( IMG2_HEIGHT - TEMPLATE2_HEIGHT ):        
        for j in range( IMG2_WIDTH - TEMPLATE2_WIDTH ):
            tmp2[i][j] = np.sum( list( map( abs, img2[j:j+ TEMPLATE2_WIDTH, i:i+TEMPLATE2_HEIGHT] - template2_90 ) ) )
            if tmp2[ num_min[0][0] ][ num_min[0][1] ] > tmp2[i][j]:
                num_min[0][0],num_min[0][1] = i, j

    print( "x={0} y={1}".format( num_min[0][0], num_min[0][1] ))    

