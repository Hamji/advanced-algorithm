## 9.5

> 중복된 문자가 없는 문자열의 모든 순열을
> 찾는 메서드를 작성하라

김건희

<details>
<summary>접기/펼치기 버튼</summary>

``` python3
  
  def permutation(s, pre):
  if len(s) == 0:
    print(pre)
  else:
    for i in range(len(s)):
      temp = s[:i] + s[i+1:]
      permutation(temp, pre + s[i])

permutation("abc", "")

  
```

</details>
