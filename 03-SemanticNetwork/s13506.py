# 生物の概念
class Creature():
    # メンバの初期化
    def __init__( self ):
        self.creature_data = {'呼吸':'Yes'}

    # 生物の持っている属性と照合 
    def creature_have( self, inquiry ):
        print( '生物です' )
        if self.creature_data.get(inquiry): # 照合できたので結果を返す
            return  (0, self.creature_data[inquiry])
        else:                               # 最上位なので無し
            print('生物でもわからない')
            return (1, 'わからない')

# 鳥の概念        
class Bird( Creature ):
    # メンバの初期化
    def __init__( self ):
        super(Bird, self).__init__()
        self.bird_data = {'翼':'Yes'}

    # 鳥の持っている属性と照合 
    def bird_have( self, inquiry ):
        print( '鳥です' )
        if self.bird_data.get(inquiry):     # 照合できたので結果を返す
            return  (0, self.bird_data[inquiry])
        else:                               # 属性と照合できなかったので上位へ
            print('鳥ではわからないので上位へ')
            return super().creature_have( inquiry )

# オウムの概念
class Parrot( Bird ):
    # メンバの初期化
    def __init__( self ):
        super(Parrot, self).__init__()
        self.parrot_data = {'特技':'モノマネ'}

    # オウムの持っている属性と照合
    def parrot_have( self,inquiry ):
        if self.parrot_data.get(inquiry):   # 照合できたので結果を返す
            return  (0, self.parrot_data[inquiry])
        else:                               # 属性と照合できなかったので上位へ
            print('オームではわからないので上位へ')
            return super().bird_have( inquiry )
            
if __name__ == "__main__":
    parrot = Parrot()   # オウムクラスの生成

    while 1:
        question = input('質問:')
        if question == 'オームの特技は何ですか':
            print( parrot.parrot_have( '特技' )[1] )  # オウムの属性と照合
        if question == 'オームは呼吸するか':
            print( parrot.parrot_have( '呼吸' )[1] )  # オウムの属性と照合
    

    
    
    
