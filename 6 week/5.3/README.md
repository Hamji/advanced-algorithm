## 5.23

> `양의 정수 x`가 입력으로 주어진다고 하자. 이 정수를 이진수로 표현했을 때, `1인 비트의 개수가 n`이라고 하자.  
> 이진수로 표현했을 때 1인 비트 개수가 n인 다른 정수 중에서 `x 보다 작은 것 중 가장 큰 정수`와 `x 보다 큰 것 중 가장 작은 정수`를 찾아라.

황규도
<details> 
<summary>접기/펼치기 버튼</summary>
  
```python
  
import math
def getNext(x):
    n = x
    c0 = 0
    c1 = 0
    while n > 0 and n & 1 == 0:
        c0 += 1
        n >>= 1
        
    while n & 1 == 1:
        c1 += 1
        n >>= 1
    
    p = c0 + c1
    
    # Pivot 1로 set
    x |= (1 << p) # set Pivot 
    c1 -= 1
    
    #Pivot  기준으로 모두 reset 하고
    x &= ~((1 << p) - 1) # reset x[p:]
    
    # setBits 개수만큼 우측으로부터 set
    x |= (1 << c1) - 1
    
    print("Next : ", str(bin(x))[2:])
    return x
    

def getPrevious(x):
    n = x
    c0 = 0
    c1 = 0
    
    while n & 1 == 1:
        c1 += 1
        n >>= 1
        
    while n > 0 and n & 1 == 0:
        c0 += 1
        n >>= 1
        
    p = c0 + c1
    
    # pivot을 0으로 reset
    x &= ~(1 << p) 
    c0 -= 1
    
    # Pivot 우측을 모두 1로 set
    x |= (1 << p) - 1
    
    # c0 개수만큼 reset
    x &= ~((1 << c0)-1)
    
    print("Prev : ", str(bin(x))[2:])
    
    return x
    

def solve(x):
    print("X: ", str(bin(x))[2:])
    
    return getNext(x), getPrevious(x)
    
        

```


```python
solve(25)

solve(32)

solve(13)
```

    X:  11001
    Next :  11010
    Prev :  10110
    X:  100000
    Next :  1000000
    Prev :  10000
    X:  1101
    Next :  1110
    Prev :  1011
    



```python


</details>
