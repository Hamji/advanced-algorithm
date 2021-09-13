## 1.2
> 단방향 연결 리스트에서, 뒤에서 k 번째 원소를 찾는 알고리즘을 구현하라.

김건희
<details>
<summary>접기/펼치기 버튼</summary>

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
