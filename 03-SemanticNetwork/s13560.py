import inspect
class creature():

    def __init__( self ):
        self.breath = {'呼吸':'yes'}


    def c_have(self,word):

        if self.breath(word):
            return  (0, self.breath[word])

class bird( creature ):

    def __init__( self ):
        super(bird, self).__init__()
        self.wing = {'翼':'yes'}

    def b_have( self, word ):

        if self.wing.get(word):
            return  (0, self.wing[word])
        else:
            return super().c_have(word)

class parrot( bird ):

    def __init__( self ):
        super(parrot, self).__init__()
        self.skill = {'特技':'モノマネ'}

    def p_have( self,word ):

        if self.skill(word):

            return  (0, self.skill[word])
        else:
            return super().b_have(word)

if __name__ == "__main__":
    c = creature()
    b = bird()
    p = parrot()

    Q = input('質問をしてください:')

    if Q == 'オ-ムの特技は何ですか':
        print( p.p_have( '特技' )[1] )
    if Q == 'オームは呼吸するか':
        print( p.p_have( '呼吸' )[1] )
