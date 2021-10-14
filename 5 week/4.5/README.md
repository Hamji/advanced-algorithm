### 4.5  

> 어떤 이진 트리가 이진 탐색 트리인지 판별하는 함수를 구현하라.

<details> 박수원
<summary>접기/펼치기 버튼</summary>

```C
// 이진 탐색 트리인 경우
// 왼쪽 노드가 부모 노드보다 작아야하며, 오른쪽 노드가 부모 노드보다 커야한다.
// 중첩 노드는 존재하지 않는다.

// pseudo code
func isBST(nod)
  if node.left > node or node.right < node
    return false
  return isBST(node.left) || isBST(node.right)
```

[C 언어 소스 코드](4.5.c)
</details>
