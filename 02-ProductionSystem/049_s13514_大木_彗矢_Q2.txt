wm=["a","*","b","-","c","d","/","e","+","f","g"]
gole=["g","f","e","d","c","b","a","+","-","*","/"]


while not wm==gole:
    for i in range(10):#+,-,*,/の文字の時、右の文字と入れ替える
        print (wm)
        if wm[i]=="+":
               wm[i],wm[i+1]=wm[i+1],wm[i]
      
        if wm[i]=="-":
               wm[i],wm[i+1]=wm[i+1],wm[i]
                
        if wm[i]=="*":
               wm[i],wm[i+1]=wm[i+1],wm[i]
               
        if wm[i]=="/":
               wm[i],wm[i+1]=wm[i+1],wm[i]

       
        if wm[i]=="a":#aの左にｂがないなら左の文字と入れ替える
            if not wm[i-1]=="b"and not i==0:
                wm[i],wm[i-1]=wm[i-1],wm[i]
        if wm[i]=="b":#ｂの左にcがないなら左の文字と入れ替える
            if not  wm[i-1]=="c"and not i==0:
                wm[i],wm[i-1]=wm[i-1],wm[i]
        if wm[i]=="c":#cの左にdがないなら左の文字と入れ替える
            if not  wm[i-1]=="d"and not i==0:
                wm[i],wm[i-1]=wm[i-1],wm[i]
        if wm[i]=="d":#dの左にeがないなら左の文字と入れ替える
            if not  wm[i-1]=="e"and not i==0:
                wm[i],wm[i-1]=wm[i-1],wm[i]
        if wm[i]=="e":#eの左にfがないなら左の文字と入れ替える
            if  not wm[i-1]=="f"and not i==0:
                wm[i],wm[i-1]=wm[i-1],wm[i]    
        if wm[i]=="f":#fの左にgがないなら左の文字と入れ替える
            if  not wm[i-1]=="g"and not i==0:
                wm[i],wm[i-1]=wm[i-1],wm[i]
        if wm[i]=="g":#gの右にfがないなら左の文字と入れ替える
            if  not wm[i+1]=="f"and not i==0:
                wm[i],wm[i-1]=wm[i-1],wm[i]