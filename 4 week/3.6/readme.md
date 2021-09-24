## 3.6

> 큰 값이 위에 오도록 스택을 오름차순 정렬하는 프로그램을 작성하라.  
> 영벌 스택은 하나까지만 사용할 수 있고, 스택에 보관된 요소를 배열 등의 다른 자료구조로는 복사할 수 없다.  
> 스택은 `push`, `pop`, `peek`, `isEmpty` 의 네 가지 연산을 제공한다.  

황규도
<details>
<summary>접기/펼치기 버튼</summary>

```python
class Stack:
    def __init__(self):
        self.stack = []
        
    def pop(self):
        return self.stack.pop()
    
    def push(self, data):
        self.stack.append(data)
        
    def peek(self):
        return self.stack[-1]
    
    def isEmpty(self):
        return len(self.stack) == 0
    
    def __str__(self):
        return str(self.stack)
```


```python
import random
unsorted = Stack()
for i in range(10):
    unsorted.push(random.randint(1, 100))
print(unsorted)

descendingStack = Stack()
temp = None
while not unsorted.isEmpty():
    print("================================")
    print("[*] unsorted : " + str(unsorted))
    print("[*] descening: " + str(descendingStack))
    print("[*] Temp     : " + str(temp))
    if descendingStack.isEmpty() or descendingStack.peek() >= unsorted.peek():
        descendingStack.push(unsorted.pop())
    else:
        temp = unsorted.pop()
        while not descendingStack.isEmpty():
            unsorted.push(descendingStack.pop())
            
        while unsorted.peek() >= temp:
            descendingStack.push(unsorted.pop())
        descendingStack.push(temp)
        temp = None

print(descendingStack)
```

    [16, 90, 28, 70, 46, 39, 24, 3, 31, 41]
    ================================
    [*] unsorted : [16, 90, 28, 70, 46, 39, 24, 3, 31, 41]
    [*] descening: []
    [*] Temp     : None
    ================================
    [*] unsorted : [16, 90, 28, 70, 46, 39, 24, 3, 31]
    [*] descening: [41]
    [*] Temp     : None
    ================================
    [*] unsorted : [16, 90, 28, 70, 46, 39, 24, 3]
    [*] descening: [41, 31]
    [*] Temp     : None
    ================================
    [*] unsorted : [16, 90, 28, 70, 46, 39, 24]
    [*] descening: [41, 31, 3]
    [*] Temp     : None
    ================================
    [*] unsorted : [16, 90, 28, 70, 46, 39, 3]
    [*] descening: [41, 31, 24]
    [*] Temp     : None
    ================================
    [*] unsorted : [16, 90, 28, 70, 46, 39]
    [*] descening: [41, 31, 24, 3]
    [*] Temp     : None
    ================================
    [*] unsorted : [16, 90, 28, 70, 46, 3, 24, 31]
    [*] descening: [41, 39]
    [*] Temp     : None
    ================================
    [*] unsorted : [16, 90, 28, 70, 46, 3, 24]
    [*] descening: [41, 39, 31]
    [*] Temp     : None
    ================================
    [*] unsorted : [16, 90, 28, 70, 46, 3]
    [*] descening: [41, 39, 31, 24]
    [*] Temp     : None
    ================================
    [*] unsorted : [16, 90, 28, 70, 46]
    [*] descening: [41, 39, 31, 24, 3]
    [*] Temp     : None
    ================================
    [*] unsorted : [16, 90, 28, 70, 3, 24, 31, 39, 41]
    [*] descening: [46]
    [*] Temp     : None
    ================================
    [*] unsorted : [16, 90, 28, 70, 3, 24, 31, 39]
    [*] descening: [46, 41]
    [*] Temp     : None
    ================================
    [*] unsorted : [16, 90, 28, 70, 3, 24, 31]
    [*] descening: [46, 41, 39]
    [*] Temp     : None
    ================================
    [*] unsorted : [16, 90, 28, 70, 3, 24]
    [*] descening: [46, 41, 39, 31]
    [*] Temp     : None
    ================================
    [*] unsorted : [16, 90, 28, 70, 3]
    [*] descening: [46, 41, 39, 31, 24]
    [*] Temp     : None
    ================================
    [*] unsorted : [16, 90, 28, 70]
    [*] descening: [46, 41, 39, 31, 24, 3]
    [*] Temp     : None
    ================================
    [*] unsorted : [16, 90, 28, 3, 24, 31, 39, 41, 46]
    [*] descening: [70]
    [*] Temp     : None
    ================================
    [*] unsorted : [16, 90, 28, 3, 24, 31, 39, 41]
    [*] descening: [70, 46]
    [*] Temp     : None
    ================================
    [*] unsorted : [16, 90, 28, 3, 24, 31, 39]
    [*] descening: [70, 46, 41]
    [*] Temp     : None
    ================================
    [*] unsorted : [16, 90, 28, 3, 24, 31]
    [*] descening: [70, 46, 41, 39]
    [*] Temp     : None
    ================================
    [*] unsorted : [16, 90, 28, 3, 24]
    [*] descening: [70, 46, 41, 39, 31]
    [*] Temp     : None
    ================================
    [*] unsorted : [16, 90, 28, 3]
    [*] descening: [70, 46, 41, 39, 31, 24]
    [*] Temp     : None
    ================================
    [*] unsorted : [16, 90, 28]
    [*] descening: [70, 46, 41, 39, 31, 24, 3]
    [*] Temp     : None
    ================================
    [*] unsorted : [16, 90, 3, 24]
    [*] descening: [70, 46, 41, 39, 31, 28]
    [*] Temp     : None
    ================================
    [*] unsorted : [16, 90, 3]
    [*] descening: [70, 46, 41, 39, 31, 28, 24]
    [*] Temp     : None
    ================================
    [*] unsorted : [16, 90]
    [*] descening: [70, 46, 41, 39, 31, 28, 24, 3]
    [*] Temp     : None
    ================================
    [*] unsorted : [16, 3, 24, 28, 31, 39, 41, 46, 70]
    [*] descening: [90]
    [*] Temp     : None
    ================================
    [*] unsorted : [16, 3, 24, 28, 31, 39, 41, 46]
    [*] descening: [90, 70]
    [*] Temp     : None
    ================================
    [*] unsorted : [16, 3, 24, 28, 31, 39, 41]
    [*] descening: [90, 70, 46]
    [*] Temp     : None
    ================================
    [*] unsorted : [16, 3, 24, 28, 31, 39]
    [*] descening: [90, 70, 46, 41]
    [*] Temp     : None
    ================================
    [*] unsorted : [16, 3, 24, 28, 31]
    [*] descening: [90, 70, 46, 41, 39]
    [*] Temp     : None
    ================================
    [*] unsorted : [16, 3, 24, 28]
    [*] descening: [90, 70, 46, 41, 39, 31]
    [*] Temp     : None
    ================================
    [*] unsorted : [16, 3, 24]
    [*] descening: [90, 70, 46, 41, 39, 31, 28]
    [*] Temp     : None
    ================================
    [*] unsorted : [16, 3]
    [*] descening: [90, 70, 46, 41, 39, 31, 28, 24]
    [*] Temp     : None
    ================================
    [*] unsorted : [16]
    [*] descening: [90, 70, 46, 41, 39, 31, 28, 24, 3]
    [*] Temp     : None
    ================================
    [*] unsorted : [3]
    [*] descening: [90, 70, 46, 41, 39, 31, 28, 24, 16]
    [*] Temp     : None
    [90, 70, 46, 41, 39, 31, 28, 24, 16, 3]
    


```python

```


</details>

이재명
<details>
<summary>접기/펼치기 버튼</summary>

```C++
#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

template <class T>
inline void push(stack<T> &s, const T val)
{
    s.push(val);
}

template <class T>
inline const T pop(stack<T> &s)
{
    const T ret = s.top();
    s.pop();
    return ret;
}

template <class T>
inline const T peek(const stack<T> &s)
{
    return s.top();
}

template <class T>
inline const bool isEmpty(const stack<T> &s)
{
    return s.empty();
}

void sort(stack<int> &in, stack<int> &out)
{
    if ( isEmpty(in) ) return;
    push(out, pop(in));

    while ( !isEmpty(in) )
    {
        if ( peek(in) >= peek(out) )
        {
            push(out, pop(in));
        }
        else
        {
            const auto val = pop(in);

            int cnt = 0;
            while ( !isEmpty(out) && peek(out) > val )
            {
                push(in, pop(out));
                ++cnt;
            }
            push(out, val);
            while ( cnt-- )
            {
                push(out, pop(in));
            }
        }
    }
}

void print_out(stack<int> s)
{
    bool space_needed = false;
    printf("[");
    while ( !isEmpty(s) )
    {
        printf("%s%02d", space_needed ? " " : "", pop(s));
        space_needed = true;
    }
    printf("]");
}

int main()
{
    stack<int> target;
    srand(100);
    for ( int i = 0; i < 10; ++i )
    {
        push(target, rand() % 100);
    }

    printf("Before: ");
    print_out(target);
    printf("\n");

    stack<int> result;
    sort(target, result);

    printf("After: ");
    print_out(result);
    printf("\n");

    return 0;
}
```
