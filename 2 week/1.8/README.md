## 1.8

> 한 단어가 다른 단어에 포함된 문자열인지 판별하는 isSubstring이라는 메서드가 있다고 하자. 
> s1과 s2의 두 분자열이 주어졌을 때, 
> s2가 s1을 회전시킨 결과인지 판별하는 코드를 isSubstring을 한 번만 호출하도록 하여 작성하라.
> (가령 'waterbottle'은 'erbottlewat'을 회전시켜 얻을 수 있는 문자열이다)

건희
<details>
<summary>접기/펼치기 버튼</summary>

 ``` python
      
import sys

def isSubstring(big, small):
    return True if small in big else False


if __name__ == '__main__':
    args = sys.argv[1:]
    big = args[0] * 2
    small = args[1]
    
    if len(args[0]) == len(args[1]):
        print(isSubstring(big, small))
    else:
        print(False)

  
 ```

</details>

김경찬
<details>
<summary>접기/펼치기 버튼</summary>  

### 개념:
특정 문자를 아무리 회전시켜도 그 문자를 2개 더한것에 포함이 된다.  
예) abc를 회전시킨다면?  
<pre>
abcabc  
abc
 bca  
  cab  
   abc  
</pre>

``` javascript
const isRotated = (input1, input2) => (input1 + input1).includes(input2);

console.log(isRotated("waterbottle", "erbottlewat")); // true
console.log(isRotated("mju", "ujm")); // false
```
