## 2.6

> 순환 리스트가 주어졌을 때, 순환되는 부분의 첫 노드를 반환하는 알고리즘을 작성하라
> - 정의
> 순환 연결 리스트는 노드의 next 포인터가 앞선 노드들 가운데 어느 하나를 가리키도록 설정되어 있는 연결 리스트다  
> (망가진 연결 리스트라고 볼 수 있다).  
> - 예시
> 입력: A->B->C->D->E->C (E의 Next 노드가 D 앞에 있는 C로 설정되어 있다)  
> 출력: C  
---
 

황규도
<details>
 
## Concept 1:
  방문한 노드 저장 후, 매 Iteration 마다 노드의 방문 여부를 체크  
  O(N^2), extra memory  
  1. 저장 방식(Key-Value, HashTable, 그래프, ... etc)에 따라 O(N)/O(V+E)까지 가능  
  
<summary>접기/펼치기 버튼</summary>
  
``` Python

# ========================================
# O(N^2), 심지어 별도의 space 까지!
# ========================================
def naive_solve(list: LinkedList) -> Node:
    visted = []
    for node in list:
        if node in visted:
            return node
        visted.append(node)
    return None


```

</details>

김경찬
<details>
<summary>접기/펼치기 버튼</summary>
 
### 개념
#### 1. 노드에 유일한 문자열이 들어있다면: O(n)
 Charset의 범위만큼의 배열을 만들어 링크드리스트를 순회하면서 노드 데이터의 문자 코드를 인덱스로하여 발견여부를 체크한다.  
 발견 했으면 그 노드를 반환한다.
 
#### 2. 노드끼리 중복된 문자열이 허용된다면: O(n^2) 예상
 Set 자료구조에 노드의 주소값을 넣어둔다. 링크드리스트를 순회하면서 노드의 주소값이 Set에 있는지 체크한다.  
 Set에 있다면 해당 노드를 반환한다. 
 
 ---
 
#### 문제풀이
  
``` javascript
// 자바스크립트는 포인터가 없어 부득이하게 2번구현 방식이지만 문자열이 유일하다고 가정한다.
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
}

// 정답부분
function solution(input) {
  const set = new Set();
  let cur = input.head;
  while (cur) {
    if (set.has(cur.data)) {
      return cur;
    } else {
      set.add(cur.data);
      cur = cur.next;
      if (cur == null) {
        return null;
      }
    }
  }
}

// 문제 초기화
const linkedList = new LinkedList();
const node1 = new Node("A");
const node2 = new Node("B");
const node3 = new Node("C");
const node4 = new Node("D");
const node5 = new Node("E");
node1.next = node2;
node2.next = node3;
node3.next = node4;
node4.next = node5;
node5.next = node3;
linkedList.head = node1;

console.log(solution(linkedList));



```

</details>
