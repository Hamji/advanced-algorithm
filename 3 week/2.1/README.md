## 2.1

> 비정렬 연결 리스트에서 중복 문자를 제거하는 코드를 작성하라.
> + 임시 버퍼가 허용되지 않는 상황에서 이 문제를 어떻게 해결할 수 있겠는가?

---
황규도
<details>
<summary>접기/펼치기 버튼</summary>

``` Python

class LinkedList:
    class Node:
        def __init__(self, data):
            self.data = data
            self.prev = None
            self.next = None

        def __lt__(self, other):
            return self.data < other.data

    class iterator:
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
        self.tail = None

    def add(self, data):
        new_node = self.Node(data)
        new_node.next = None

        if self.head is None:
            self.head = new_node
            new_node.prev = None
        else:
            self.tail.next = new_node
            new_node.prev = self.tail

        self.tail = new_node

    def __iter__(self):
        return self.iterator(self)

    def __str__(self):
        myStr = ""
        head = self.head
        while head is not None:
            myStr += str(head.data)
            head = head.next
        return myStr

# ========================================================
# O(N) solve, 버퍼 O
# ========================================================
def solve_naive(unsorted: LinkedList) -> LinkedList:
    alphabets = set()
    for node in unsorted:
        alphabets.add(node.data)

    result = LinkedList()
    for alphabet in alphabets:
        result.add(alphabet)
    return result


# ========================================================
# O(N) solve, 버퍼 ?
# ========================================================
def solve(unsorted: LinkedList) -> LinkedList:
    alphabet = 0

    # 알파벳 저장
    for node in unsorted:
        mask = 1 << ord(node.data) - ord("a")
        alphabet |= mask

    # list 수정
    node_iterator = unsorted.__iter__()
    while True:
        try:
            node = next(node_iterator)
            mask = 1 << ord(node.data) - ord("a")
            if alphabet & mask > 0:
                alphabet &= ~ mask
            else:
                if node.next is not None:
                    node.next.prev = node.prev
                node.prev.next = node.next
        except StopIteration:
            return unsorted




# ========================================================
# Test Code, solve_navie == solve ?
# ========================================================
import random

for _ in range(10000):
    t_list = LinkedList()
    for __ in range(random.randint(1, 50)):
        t_alphabet = chr(ord("a") + random.randint(1, 25))
        t_list.add(t_alphabet)

    t_answer = "".join(sorted(str(solve_naive(t_list))))
    c_answer = "".join(sorted(str(solve(t_list))))
    if t_answer != c_answer:
        print("%s Expected, But %s" % (t_answer, c_answer))


```


</details>
    
---
정민혁
<details>
<summary>접기/펼치기 버튼</summary>
    
``` Python    
    
class Node:
    def __init__(self, value, next_node):
        self.value = value
        self.next = next_node
   
class LinkedList:
    def __init__(self):
        self.head = Node(None, None)
        self.cur = None
    
def remove_dups_with_no_buffer(self):
        self.cur = self.head
        pointer = self.head.next
        

        while True:
            self.cur = pointer
            while self.cur.next is not None:
                if pointer.value == self.cur.next.value:
                    self.cur.next = self.cur.next.next
                else:
                    self.cur = self.cur.next
            if pointer.next is None:
                break
            else:
                pointer = pointer.next
            
    
```
</details>
김경찬
<details>
<summary>접기/펼치기 버튼</summary>
 
### 개념
M개의 노드를 갖는 링크드 리스트를 순회하면서  
    N번째 노드에 대해 N+1번째부터 M번째까지 중복검사를 하면서 중복시 해당 노드를 제거한다. 
    
 ---
 
#### 문제풀이
  
``` javascript
// 링크드리스트 구현부분
class Node {
  constructor(data, next = null) {
    this.data = data;
    this.next = next;
  }
}
class LinkedList {
  constructor() {
    this.head = null;
  }
  insertLast(node) {
    if (this.head) {
      let current = this.head;
      while (current.next) {
        current = current.next;
      }
      current.next = node;
    } else {
      this.head = node;
    }
  }
  delete(node) {
    const prev = this.findPrev(node);
    prev.next = prev.next.next;
  }
  findPrev(node) {
    let cur = this.head;
    while (cur.next != null && cur.next != node) {
      cur = cur.next;
    }
    return cur;
  }
    // 정답
  deleteDuplicate() {
    let current1 = this.head;
    while (current1) {
      let current2 = current1.next;

      while (current2) {
        if (current2.data == current1.data) {
          this.delete(current2);
        }
        current2 = current2.next;
      }
      current1 = current1.next;
    }
  }
  print() {
    let cur = this.head;
    let result = "";
    while (cur != null) {
      result += `${cur.data}=>`;
      cur = cur.next;
    }
    console.log(result);
  }
}
// 문제 초기화
const linkedList = new LinkedList();
linkedList.insertLast(new Node("A"));
linkedList.insertLast(new Node("B"));
linkedList.insertLast(new Node("C"));
linkedList.insertLast(new Node("A"));
linkedList.insertLast(new Node("D"));
linkedList.insertLast(new Node("E"));
linkedList.insertLast(new Node("D"));
linkedList.insertLast(new Node("E"));

linkedList.print(); // A=>B=>C=>A=>D=>E=>D=>E=>
linkedList.deleteDuplicate();
linkedList.print(); // A=>B=>C=>D=>E=>
