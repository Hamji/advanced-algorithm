## 3.3  

> 접시 무더기를 떠올려 보자.  
> 접시를 너무 높이 쌓으면, 넘어질 것이다.  
> 그러므로 현실에서는 무더기 높이가 특정한 수준 이상으로 높아지면 새로운 무더기를 만든다.
> 이것을 흉내 내는 자료구조 `SetOfStacks`를 구현해 보라.  
> `SetOfStacks`는 여러 스택으로 구성되어야 하며, 이전 스택이 지정된 용량을 초과하는 경우 새로운 스택을 생성해야 한다.  
> `SetOfStacks.push()`와 `SetOfStacks.pop()`은 스택이 하나인 경우와 동일하게 동작해야 한다.  
> (다시 말해, `pop()`은 저오학히 하나의 스택이 있을 때와 동일한 값을 반환해야 한다)  


## 연관 문제  
> 특정한 하위 스택에 대해서 `pop`을 수행하는 `popAt`함수(int index)를 구현하라



황규도
<details>
<summary>접기/펼치기 버튼</summary>

```python
class Stack:
    def __init__(self):
        self.stack = []
        
    def pop(self):
        return self.stack.pop()
    
    def push(self, data):
        self.stack.append(data)
        
    def peek(self):
        return self.stack[-1]
    
    def isEmpty(self):
        return len(self.stack) == 0
    
    def size(self):
        return len(self.stack)

    def __str__(self):
        return str(self.stack)
    
    def __reversed__(self):
        return reversed(self.stack)
    
class SetOfStacks:
    def __init__(self, maximum=10):
        self.maximum = maximum
        self.stacks = [Stack()]
    
    def push(self, data):
        if self.isEmpty():
            self.stacks.append(Stack())

        stack = self.stacks[-1]
        if stack.size() >= self.maximum:
            self.stacks.append(Stack())
            stack = self.stacks[-1]
        
        stack.push(data)
        
    def pop(self):
        stack = self.stacks[-1]
        data = stack.pop()
        
        if stack.isEmpty():
            self.stacks = self.stacks[:-1]
        return data
        
    def isEmpty(self):
        return len(self.stacks) == 0
    
    def __str__(self):
        res = "["
        for stack in reversed(self.stacks):
            for i in reversed(stack):
                res += str(i) + ", "
        return res + "]"
```


```python
import random
ss = SetOfStacks(maximum = 4)
for i in range(20):
    print("[*] Stacks : " + str(ss))
    if random.randint(1, 4) == 1 and not ss.isEmpty():
        print("[*] Poped  : " + str(ss.pop()))
    else:
        data = random.randint(1, 40)
        print("[*] Pushed : " + str(data))
        ss.push(data)
        
```

    [*] Stacks : []
    [*] Pushed : 30
    [*] Stacks : [30, ]
    [*] Poped  : 30
    [*] Stacks : []
    [*] Pushed : 1
    [*] Stacks : [1, ]
    [*] Pushed : 35
    [*] Stacks : [35, 1, ]
    [*] Pushed : 14
    [*] Stacks : [14, 35, 1, ]
    [*] Pushed : 40
    [*] Stacks : [40, 14, 35, 1, ]
    [*] Pushed : 34
    [*] Stacks : [34, 40, 14, 35, 1, ]
    [*] Pushed : 21
    [*] Stacks : [21, 34, 40, 14, 35, 1, ]
    [*] Pushed : 31
    [*] Stacks : [31, 21, 34, 40, 14, 35, 1, ]
    [*] Pushed : 23
    [*] Stacks : [23, 31, 21, 34, 40, 14, 35, 1, ]
    [*] Pushed : 11
    [*] Stacks : [11, 23, 31, 21, 34, 40, 14, 35, 1, ]
    [*] Pushed : 8
    [*] Stacks : [8, 11, 23, 31, 21, 34, 40, 14, 35, 1, ]
    [*] Pushed : 40
    [*] Stacks : [40, 8, 11, 23, 31, 21, 34, 40, 14, 35, 1, ]
    [*] Pushed : 33
    [*] Stacks : [33, 40, 8, 11, 23, 31, 21, 34, 40, 14, 35, 1, ]
    [*] Pushed : 26
    [*] Stacks : [26, 33, 40, 8, 11, 23, 31, 21, 34, 40, 14, 35, 1, ]
    [*] Poped  : 26
    [*] Stacks : [33, 40, 8, 11, 23, 31, 21, 34, 40, 14, 35, 1, ]
    [*] Poped  : 33
    [*] Stacks : [40, 8, 11, 23, 31, 21, 34, 40, 14, 35, 1, ]
    [*] Pushed : 22
    [*] Stacks : [22, 40, 8, 11, 23, 31, 21, 34, 40, 14, 35, 1, ]
    [*] Pushed : 23
    [*] Stacks : [23, 22, 40, 8, 11, 23, 31, 21, 34, 40, 14, 35, 1, ]
    [*] Pushed : 28
    


```python

```


```python

```


</details>
