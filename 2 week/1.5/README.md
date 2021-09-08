## 1.5
> 같은 문자가 연속으로 반복될 경우, 그 횟수를 사용해 문자열을 압축하는 메서드를 구현하라. 
> 가령 압축해야 할 문자열이 aabccccccccaaa라면 a2b1c8a3과 같이 압축되어야 한다.
> 압축 결과로 만들어지는 문자열이 원래 문자열보다 짧아지지 않는 경우, 이 메서드는 원래 문자열을 그대로 반환해야 한다.

건희
<details>
<summary>접기/펼치기 버튼</summary>

 

``` python

from collections import defaultdict

string = input()

result, current_char = "", ""
count = 0

# current_char가 바뀔때 마다 이전에 
# 세주었던 문자의 갯수와 해당 문자를 result에 붙여준다.
# 그리고 current_char 를 새로운 문자로 바꾸고 count를 1로 바꾼다.
for i in string:
    if i != current_char:
        if count != 0:
            result += str(count) + current_char
        current_char = i
        count = 1
    else:
        count+=1

result += str(count) + current_char

# 현재 문자열보다 짧아지지 않는 경우 걍 원래대로 출력하겠다...
if len(string) <= len(result):
    print(string)
else:
    print(result)


```



</details>
