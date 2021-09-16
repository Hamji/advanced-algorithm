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
