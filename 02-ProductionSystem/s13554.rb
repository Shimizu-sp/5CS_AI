# coding: utf-8
def MatchPattern(text)
  p text
  x = " "#1文字目
  y = " "#2文字目
  v = " "#1記号目
  w = " "#2記号目
  #x,y→文字 v,w→記号
  if text.include?("$") then
    n = text.index("$") #$の0から始まるインデックスを取得 文字列の最後かもしれない
    case ((text.length - 1) - n)
      when 0 then#$が文字の最後の時
      when 1 then#後ろに1文字ある場合
        if (/[a-z]/ =~ text[n + 1,text.length]) == 0
          x =  text[n + 1]#文字
        else
          v = text[n + 1]#記号
        end

      when 2 then#後ろに2文字ある場合
        ####################1文字目が記号か文字か
        if (/[a-z]/ =~ text[n + 1,text.length]) == 0
          x =  text[n + 1]#文字
        else
          v = text[n + 1]#記号
        end

        ####################2文字目
        if !(text.include?("$"+x+"$") || text.include?("$"+v+"$"))#$は制御文字のため，2文字目に$がきても無視する
          if (/[a-z]/ =~ text[n + 2,text.length]) == 0#2文字目が文字か記号か
            y = text[n + 2]#文字
          else
            w = text[n + 2]#記号
          end
        end
      else#後ろに3文字以上ある場合

        ####################1文字目
        if (/[a-z]/ =~ text[n + 1,text.length]) == 0
          x =  text[n + 1]#文字
        else
          v = text[n + 1]#記号
        end

        ####################2文字目
        if !(text.include?("$"+x+"$") || text.include?("$"+v+"$"))#$は制御文字のため，2文字目に$がきても無視する
          if (/[a-z]/ =~ text[n + 2,text.length]) == 0
            y = text[n + 2]
          else
            w = text[n + 2]
          end
        end
      end
  end
  #制御文字である?の操作，基本的に$と一緒
  if text.include?("?") then
    m = text.index("?")
    case ((text.length - 1) - m)
      when 0 then#文字の最後の時
      when 1 then#後ろに1文字
        if (/[a-z]/ =~ text[m + 1,text.length]) == 0
          x = text[m + 1]#文字
        else
          v = text[m + 1]#記号
        end
      when 2 then#後ろに2文字
        ####################1文字目
        if (/[a-z]/ =~ text[n + 1,text.length]) == 0
          x =  text[m + 1]#文字
        else
          v = text[m + 1]#記号
        end
        ####################2文字目
        if !(text.include?("?"+x+"?") || text.include?("?"+v+"?"))
          if (/[a-z]/ =~ text[m + 2,text.length]) == 0
            y = text[m + 2]
          else
            w = text[m + 2]
          end
        end
      else#後ろに3文字以上ある時
        ####################1文字目
        if (/[a-z]/ =~ text[m + 1,text.length]) == 0
          x =  text[m + 1]#文字
        else
          v = text[m + 1]#記号
        end

        ####################2文字目
        if !(text.include?("?"+x+"?") || text.include?("?"+v+"?"))
          #p "b"
          if (/[a-z]/ =~ text[m + 2,text.length]) == 0
            y = text[m + 2]
          else
            w = text[m + 2]
          end
        end
      end
  end

  symbol = "+-*/"#記号部分の正解順序
  if text.include?("$$") then#ルール1
    text.gsub!("$$","?")
    return text
  elsif text.include?("?$") then#ルール2
    text.gsub!("?$","?")
    return text
  elsif text.include?("?"+x) then#ルール3
    text.gsub!("?"+x,x+"?")
    return text
  elsif text.include?("?"+v) then#ルール4
    text.gsub!("?"+v,v+"?")
    return text
  elsif text.include?("?") then#ルール5
    text.delete!("?")
    return text
  elsif text.include?("$"+x+y) then#ルール6
    if x < y
      text.gsub!("$"+x+y,y+"$"+x)####
    else
      text.gsub!("$"+x+y,x+"$"+y)####
    end
    return text
  elsif text.include?("$"+v+y) then#ルール7
    text.gsub!("$"+v+y,y+"$"+v)
    return text
  elsif text.include?("$"+v+w) then#ルール8
    v_num = text.index(v)
    w_num = text.index(w)
    symbol_v_num = symbol.index(v)
    symbol_w_num = symbol.index(w)
    if (v_num < w_num && symbol_v_num < symbol_w_num) || (v_num > w_num && symbol_v_num > symbol_w_num)
      text.gsub!("$"+v+w,v+"$"+w)####
    else
      text.gsub!("$"+v+w,w+"$"+v)####
    end
    return text
  elsif text.include?("$"+x+w)  then#ルール9
    text.gsub!("$"+x+w,x+"$"+w)
    return text
  else #ルール10
    text.insert(0,"$")
    return text
  end
end

if __FILE__ == $0#main
  problem = "a*b-cd/e+fg"

  #下のコメントを外すとランダム文字列
  #array = ["a","b","c","d","e","f","g","+","-","*","/"]
  #problem = ""
  #for char in array.sort_by{rand} do
  #  problem << char
  #end

  p problem
  problemtext = ""
  problemtext << problem
  while problem != "gfedcba+-*/"
    problem = MatchPattern(problem)
    if problem.eql?("gfedcba+-*/")
      break
    end
  end
  p "完成文字列:" + problem
  p "初期文字列:" + problemtext
end
