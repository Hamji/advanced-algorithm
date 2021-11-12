## 7.7

> 3, 5, 7 세 소수만을 약수로 가지는 K 번째 수를 찾는 알고리즘을 설계하라.



김건희
<details>
<summary>접기/펼치기 버튼</summary>

``` python
  
  def getK(k):
  result = 0
  li3 = [1]
  li5 = []
  li7 = []

  for i in range(0, k + 1):
    temp3 = li3[0] if li3 else 999999
    temp5 = li5[0] if li5 else 999999
    temp7 = li7[0] if li7 else 999999

    result = min(temp3, temp5, temp7)
    if result == temp3:
      li3.pop(0)
      li3.append(3 * result)
      li5.append(5 * result)
    elif result == temp5:
      li5.pop(0)
      li5.append(5 * result)
    elif result == temp7:
      li7.pop(0)

    li7.append(7 * result)
  return result
  
print(getK(10))
  
```
  

</details>
