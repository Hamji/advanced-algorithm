## 4.1 

> 주어진 이진 트리가 균형 이진 트리인지 판별하는 함수를 구현하라.
> 이 문제에서 이진 트리는 어떤 노드의 두 자식 트리 깊이가 하나 이상 차이 나지 않는 트리이다.

김건희
<details>
<summary>접기/펼치기 버튼</summary>

``` python
  
  def isBalanced(root):
    
    if not root :
        return 0
    
    # 왼쪽이 balanced 한지
    left_height = isBalanced(root.left)
    if left_height == float("inf") :
        return float("inf")
 
    # 오른쪽이 balanced 한지
    right_height = isBalanced(root.right)
    if right_height == float("inf") :
        return float("inf")
 
    # 길이차 구하기
    diff = left_height - right_height 
    # 2 이상이라면 깨진 것이다.
    if abs(diff) > 1:
        return float("inf")
    else :
        return max(left_height, right_height) + 1
 
  def check(root):
 
    return isBalanced(root) != float("inf")
  
```
  
</details>
