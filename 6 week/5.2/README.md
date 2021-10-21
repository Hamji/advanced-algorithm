## 5.2 

> 0 과 1 사이의 실수가 double 타입의 입력으로 주워졌을 때, 그 값을 이진수 형태로 출력하는 코드를 작성하여라. 
> 길이가 32 이하 문자열로 출력될 수 없는 경우에는, ERROR를 대신 출력하자

김건희

<details>
<summary>접기/펼치기 버튼</summary>

``` python

value = 0.625

if not (0 < value < 1):
  print("ERROR")
  exit()

result = ""
while(value > 0):
  if len(result) >= 32:
    print("ERROR: TOO LONG")
    exit()

  r = value * 2;
  if r >= 1: 
    result += "1"
    value = r -1
  else :
    result += "0"
    value = r
  #print(result)
  
print(result)
  


```

</details>
