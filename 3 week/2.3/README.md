## 2.3

> 단방향 연결 리스트의 중간에 있는 노드 하나를 삭제하는 알고리즘을 구현하라.
> 삭제할 노드에 대한 접근만 가능하다는 것에 유의하라.

---

수원

<details>
<summary>접기/펼치기 버튼</summary>

``` c

/**
 * @brief 단방향 연결 리스트의 중간에 있는 노드 하나를 삭제하는 알고리즘을 구현하라. 삭제할 노드에 대한 접근만 가능하다는 것에 유의하라.
 * 
 * Distributor ID: Ubuntu
 * Description:    Ubuntu 20.04.2 LTS
 * Release:        20.04
 * Codename:       focal
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 주어진 인자들의 개수를 반환하는 함수
 * 
 */
#define NUMARGS(...) (sizeof((int[]){0, ##__VA_ARGS__}) / sizeof(int) - 1)

/**
 * @brief list_name으로 리스트를 생성하여 나머지 인자들로 값들을 채우는 함수
 * 
 * @param list_name // 리스트의 이름
 */
#define DECLARE_LIST(list_name, ...)                      \
    struct node *list_name = malloc(sizeof(struct node)); \
    list_name->next = NULL;                               \
    do                                                    \
    {                                                     \
        if (NUMARGS(__VA_ARGS__) <= 0)                    \
            break;                                        \
        int _t[] = {__VA_ARGS__};                         \
        int _numt = sizeof _t / sizeof _t[0];             \
        struct node *_temp = list_name;                   \
        for (int _i = 0; _i < _numt; _i++)                \
        {                                                 \
            _temp->data = _t[_i];                         \
            if (_i >= _numt - 1)                          \
            {                                             \
                _temp->next = NULL;                       \
                break;                                    \
            }                                             \
            _temp->next = malloc(sizeof(struct node));    \
            _temp = _temp->next;                          \
        }                                                 \
    } while (0)

/**
 * @brief 리스트의 끝까지 출력하는 함수
 * 
 * @param list_name // 리스트의 이름
 */
#define PRINT_LIST(list_name)                                                            \
    do                                                                                   \
    {                                                                                    \
        printf("START ->");                                                              \
        for (struct node *_cursor = list_name; _cursor != NULL; _cursor = _cursor->next) \
            printf(" %d ->", _cursor->data);                                             \
        printf(" END\n");                                                                \
    } while (0)

struct node
{
    int data;
    struct node *next;
};

/**
 * @brief 주어진 노드의 주소를 다음 노드의 주소로 바꾸고 주어졌던 노드를 삭제한다
 * 
 * @param n // 노드의 주소값 
 */
void delNode(struct node **n)
{
    // n은 NULL이 아니라고 가정
    struct node *temp = *n; // 이전 노드 백업
    *n = (*n)->next;        // n의 다음 노드의 포인터를 n으로 복사
    free(temp);             // 이전 노드 free
}

int main()
{
    DECLARE_LIST(head, 1, 2, 3, 4, 5); // 리스트 선언 함수

    PRINT_LIST(head); // 리스트 출력함수

    delNode(&head->next->next);

    PRINT_LIST(head);
}

```
  
</details>  

황규도
<details> 
<summary>접기/펼치기 버튼</summary>

## Concept  
    1. K 번째 노드에 K + 1 번째 노드의 값을 복사한다.  
    2. K 번째 노드의 next 는 K + 2 번째 노드의 주소를 저장한다.  
    
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
            result += str(curr.data) + "\n"
            curr = curr.next
        return result

# ======================================
# 중간에 있는 노드 삭제
# ======================================
def solve(linkedlist: LinkedList, k: int) -> LinkedList:
    iter = linkedlist.__iter__()
    curr_node = None
    while k > 0:
        curr_node = next(iter)
        k -= 1
        
    next_node = curr_node.next
    curr_node.data = next_node.data
    curr_node.next = next_node.next

    return linkedlist



```

</details>
    
김경찬
<details>
<summary>접기/펼치기 버튼</summary>
 
### 개념
삭제할 노드의 Next를 Next Node의 Next로 대입해주고,  
    삭제할 노드의 Data를 Next Node의 Data로 대입해주면 된다.
    
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
  //정답부분
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
let linkedList = new LinkedList();
let node1 = new Node("A");
let node2 = new Node("B");
let node3 = new Node("C");
let node4 = new Node("D");
let node5 = new Node("E");
linkedList.insertLast(node1);
linkedList.insertLast(node2);
linkedList.insertLast(node3);
linkedList.insertLast(node4);
linkedList.insertLast(node5);

linkedList.print(); // A=>B=>C=>D=>E=>
linkedList.delete(node4);
linkedList.print(); // A=>B=>D=>E=>
```
