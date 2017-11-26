#各特長を定義
Animal = ['Do_呼吸']
Bird   = ['Have_翼',  'Animal']
Owm    = ['Skill_モノマネ','Bird']

#is-a関係を作る
Bird += Animal  #鳥は動物
Owm  += Bird    #オウムは鳥

cnt = 0         #cntを定義、初期化

#オームの特技って何？
print('オームの特技は?')
while(cnt < len(Owm)):  #cntの値がOwm内に定義された内容の数と同値になるまでループ
    if(Owm[cnt].find('Skill') >= 0):  #Owm配列の中に、Skill(特技)の文字が含まれる定義があったら
        print(' [ %s ]を持っています' % (Owm[cnt]))

    cnt += 1

cnt = 0
YENO = 0
#オームって呼吸するの？
print('オームは呼吸する？')
while(cnt < len(Owm)): #cntの値がOwm内に定義された内容の数と同値になるまでループ
    if(Owm[cnt].find('Do_呼吸') >= 0):    #Do_呼吸　がある場合
        print('YES')                                                               
        YENO = 1
        break

    cnt += 1

if(YENO == 0):
    print('NO')


word = input('Press Enter to Finish')