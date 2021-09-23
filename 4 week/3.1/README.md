# 3.1  

> 하나의 배열을 사용해 세 개의 스택을 구현하는 방법을 설명하라


정민혁
<details>
<summary>접기/펼치기 버튼</summary>

```python
  
stack = [[0 for col in range(10)] for row in range(3)]
stack_pointer = [-1, -1 ,-1]

def push(stack_number, value):
    if stack_pointer[stack_number] == 9:
        print("stack overflow")
    else:
        stack_pointer[stack_number]+=1
        stack[stack_number][stack_pointer[stack_number]] = value

def pop(stack_number):
    if stack_pointer[stack_number] == -1:
        print("There is no value")
        return null
    else:
        pop_value = stack[stack_number][stack_pointer[stack_number]]
        stack[stack_number][stack_pointer[stack_number]] = 0
        stack_pointer[stack_number]-=1
        return pop_value
    
print(stack)
 
```
