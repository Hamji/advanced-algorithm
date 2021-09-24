## 3.5

> 두개의 스택을 사용하여 큐를 구현하는 MyQueue 클래스를 작성하라

황규도
<details>
<summary>접기/펼치기 버튼</summary>

```python
class Stack:
    class iterator:
        def __init__(self, outer):
            self.stack = outer.stack
            self.idx = len(self.stack) - 1
            
        def __iter__(self):
            return self
        
        def __next__(self):
            if self.idx < 0:
                raise StopIteration
            data = self.stack[self.idx]
            self.idx -= 1
            return data
            
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
    
    def __str__(self):
        return str(self.stack)
    
    def __iter__(self):
        return self.iterator(self)
    
class MyQueue:
    def __init__(self):
        self.queue = Stack()
        self.stack = Stack()

        
    def enqueue(self, data):
        self.stack.push(data)
        
    def dequeue(self):
        if self.queue.isEmpty():
            while not self.stack.isEmpty():
                self.queue.push(self.stack.pop())
        return self.queue.pop()

    def isEmpty(self):
        return self.queue.isEmpty() and self.stack.isEmpty()
    
    def __str__(self):
        res = "["
        for s in self.stack:
            res += str(s) + ", "
        
        for s in self.queue:
            res += str(s) + ", "
        return res + "]"
        
```


```python
import random

q = MyQueue()
for i in range(20):
    print("============================")
    print("[*] MyQueue : " + str(q))
    if random.randint(1, 2) == 1 and not q.isEmpty():
        print("[*] I Poped  : " + str(q.dequeue()))
    else:
        data = random.randint(1, 40)
        print("[*] I Pushed : " + str(data))
        q.enqueue(data)
    

```

    ============================
    [*] MyQueue : []
    [*] I Pushed : 22
    ============================
    [*] MyQueue : [22, ]
    [*] I Poped  : 22
    ============================
    [*] MyQueue : []
    [*] I Pushed : 25
    ============================
    [*] MyQueue : [25, ]
    [*] I Pushed : 15
    ============================
    [*] MyQueue : [15, 25, ]
    [*] I Poped  : 25
    ============================
    [*] MyQueue : [15, ]
    [*] I Poped  : 15
    ============================
    [*] MyQueue : []
    [*] I Pushed : 30
    ============================
    [*] MyQueue : [30, ]
    [*] I Poped  : 30
    ============================
    [*] MyQueue : []
    [*] I Pushed : 1
    ============================
    [*] MyQueue : [1, ]
    [*] I Pushed : 17
    ============================
    [*] MyQueue : [17, 1, ]
    [*] I Pushed : 19
    ============================
    [*] MyQueue : [19, 17, 1, ]
    [*] I Pushed : 12
    ============================
    [*] MyQueue : [12, 19, 17, 1, ]
    [*] I Poped  : 1
    ============================
    [*] MyQueue : [17, 19, 12, ]
    [*] I Pushed : 20
    ============================
    [*] MyQueue : [20, 17, 19, 12, ]
    [*] I Poped  : 17
    ============================
    [*] MyQueue : [20, 19, 12, ]
    [*] I Pushed : 12
    ============================
    [*] MyQueue : [12, 20, 19, 12, ]
    [*] I Pushed : 31
    ============================
    [*] MyQueue : [31, 12, 20, 19, 12, ]
    [*] I Pushed : 34
    ============================
    [*] MyQueue : [34, 31, 12, 20, 19, 12, ]
    [*] I Pushed : 20
    ============================
    [*] MyQueue : [20, 34, 31, 12, 20, 19, 12, ]
    [*] I Pushed : 20
    


```python

```


</details>
    
    
    
김건희
<details>
<summary>접기/펼치기 버튼</summary>

``` python
  
  class CustomQueue:
    first = []
    second = []

    def __init__(self, li):
        self.first = li[:]

    def push(self, val):
        self.first.append(val)

    def pop(self):
        if not self.second:
            for i in range(len(self.first)):
                self.second.append(self.first.pop())
        result = self.second.pop()
        return result

if __name__ == "__main__":
    cqueue = CustomQueue([1,2,3,4,5,6])

    print(cqueue.pop())
    print(cqueue.pop())
    print(cqueue.pop())

  
```
  
</details>
