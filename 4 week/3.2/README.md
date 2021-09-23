## 3.2

> stack 2 개로 queue 처럼 사용하기 

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
        for i in range(len(self.first)):
            self.second.append(self.first.pop())
        result = self.second.pop()
        for i in range(len(self.second)):
            self.first.append(self.second.pop())
        return result

if __name__ == "__main__":
    cqueue = CustomQueue([1,2,3,4,5,6])

    print(cqueue.pop())
    print(cqueue.pop())
    print(cqueue.pop())

  
```
  
</details>
