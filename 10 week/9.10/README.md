## 9.10

> 너비 w, 높이 h, 깊이 d의 박스 n개가 있다. 상자는 회전시킬 수 없으며, 다른 상자위에 놓이기만 할 수 있는데, 그것도 아래 놓인 상자의 너비, 높이, 깊이가 위에 놓인 상자의 너비, 높이, 깊이보다
> 더 커야만 가능하다. 이 상자들로 쌓을 수 있는 가장 높은 탑을 구하는 메서드를 작성하라. 탑의 높이는 탑을 구성하는 모든 상자의 높이 합이다.


정민혁

<details>
<summary>접기/펼치기 버튼</summary>

```python
import random

boxes = []
above_list = []

for i in range(10):
    box = [i, random.randint(1,50), random.randint(1,50), random.randint(1,50)]
    boxes.append(box)
    
def CanBeAbove(box_under, box_on):
    if(box_under[1] > box_on[1] and box_under[2] > box_on[2] and box_under[3] > box_on[3]):
        canBeOn = True
    else:
        canBeOn = False
    return canBeOn

for i in range(10):
    above_list.append([])
    for j in range(10):
        if(i!=j):
            if(CanBeAbove(boxes[i], boxes[j])):
                above_list[i].append(boxes[j][0])
print(boxes)
print(above_list)

def heightStack(box, above_boxes):
    height_list = []
    height = box[3]
    height_temp = 0
    if(len(above_boxes)!=0):
        for i in range(len(above_boxes)):
            height_list.append(heightStack(boxes[above_boxes[i]], above_list[i]))
        height_temp = max(height_list)
    else:
        return height+height_temp
        

for i in range(10):
    heightStack(boxes[i], above_list[i])
  
```

</details>
