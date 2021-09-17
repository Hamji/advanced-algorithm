## 1.2
> 단방향 연결 리스트에서, 뒤에서 k 번째 원소를 찾는 알고리즘을 구현하라.

김건희
<details>
<summary>접기/펼치기 버튼</summary>

```
   링크드 리스트를 순회하면서 stack에 값을 담아주고 뒤에서 k번째만큼 pop 해주는 방식으로  
```
    
``` python3

class Node:
    next = None
    value = -1 
    def __init__(self, value, next):
        self.next = next
        self.value = value

def makingNode(many):
    result = None
    for i in range(many):
        temp = Node(10 - i, result)
        result = temp

    return result

def printNode(nds):
    while nds != None:
        print(str(nds.value) + " " , end='')
        nds = nds.next

if __name__ == "__main__":
    nds = makingNode(10)
    stack = []
    printNode(nds)
    print('')
    print("K element : ", end='')
    val = int(input())
    
    while nds != None:
        stack.append(nds.value)
        nds = nds.next

    result = 0
    for i in range(val):
        result = stack.pop()

    print(result)




```

</details>  

황규도
<details>
<summary>접기/펼치기 버튼</summary>  
    
``` python 

class LinkedList:
    class Node:
        def __init__(self, data, next=None):
            self.data = data
            self.next = next

    class Iterator:
        def __init__(self, outer):
            self.outer = outer.head

        def __iter__(self):
            return self

        def __next__(self):
            if self.outer is None:
                raise StopIteration

            data = self.outer
            self.outer = self.outer.next

            return data

    def __init__(self):
        self.head = None

    def __iter__(self):
        return self.Iterator(self)

    def add(self, data):
        if self.head is None:
            self.head = self.Node(data)
        else:
            node = self.head
            while node.next:
                node = node.next
            node.next = self.Node(data)

        return self

    def __str__(self):
        result = ""
        curr = self.head
        while curr is not None:
            result += str(curr.data)
            curr = curr.next
        return result

def solve(linkedlist: LinkedList, k: int) -> type:
    stack = [node.data for node in linkedlist]
    for _ in range(k-1):
        stack.pop()
    return stack[-1]



```
</details>
