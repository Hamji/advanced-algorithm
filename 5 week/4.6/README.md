### 4.6  

> 정순회 기준으로, 이진 탐색 트리 내의 한 노드가 주어지면 그 노드의 `다음` 노드를 찾아내는 알고리즘을 작성하라.  
> 각 노드에는 부모 노드를 가리키는 링크가 존재한다고 가정한다.  
> Successor: Write an algorithm to find the "next" node (i.e., in-order successor) of a given node in a  
> binary search tree. You may assume that each node has a link to its parent. 

<details> 황규도
<summary>접기/펼치기 버튼</summary>

![문제](attachment:image.png)
```python
# 완전 이진 트리인 경우
# 경우의 수
#   case 1: 좌측 자식이 있는 경우
#     --> return Left(x)
#   case 2: 자식이 없는 경우
#     case 2.1: 좌측의 좌측인 경우
#        --> return Right(Parent(x))
#     case 2.2: 좌측의 우측인 경우
#        --> return Left(Parent(x))
#     case 2.3: 우측의 좌측인 경우
#        --> return Left(Right(Parent(Parent(x))))
#     case 2.4: 우측의 우측인 경우
#        --> 
#            1. 2.3 case까지 Parent(x)
#            2. 2.3 case 실행한 후, (1) 반복한 만큼 Left 연산
def nextNode(x):
    if Left(x) is not None: return Left(x)
    elif Left(x) is None:
        if Left(Parent(Parent(x))) == Parent(x) and Left(Parent(x)) == self: return Right(Parent(x))
        elif Left(Parent(Parent(x)) == Parent(x) and Right(Parent(x)) == self: return Left(Parent(x))
        elif Right(Parent(Parent(x)) == Parent(x) and Left(Parent(x)) == self: return Left(Right(Parent(Parent(x))))
        else: return Left(nextNode(x))
    

</details>
