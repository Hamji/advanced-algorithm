## 3.4  

> 하노이 탑 문제에는 3개의 탑과 N개의 원판이 등장하는데, 각 원판은 어느 탑으로도 옮길 수 있다.   
> 하노이 탑 퍼즐은 세 개의 탑 가운데 하나에 이 N개의 원판을 쌓아두고 시작한다.   
> 이 때 원판들은 지름이 작은 우너판이 위쪽에 오도록 배열된다.  
> 하노이 탑 퍼즐에는 다음과 같은 제약조건들이 있다.  
>  (1) 한 번에 하나의 원판만 옮길 수 있다.  
>  (2) 탑의 맨 꼭대기에 있는 원판은 옆에 있는 탑으로 옮길 수 있다.  
>  (3) 원판은 자기보다 지름이 큰 원판 위로만 옮길 수 있다.  
> 스택을 사용하여, 첫 번재 탑에 있는 모든 원판을 마지막 탑으로 옮기는 프로그램을 작성하라



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
    
class Hanoi:
    def __init__(self, size):
        self.size = size
        
    def __gt__(self, other):
        if self.size > other.size: return True
        else: return False
        
```


```python
A = Stack()
B = Stack()
C = Stack()

import random
n = random.randint(1, 10)
for i in reversed(range(n)):
    A.push(i+1)
    
def hanoi(n, st_from, st_to, st_aux):
    if n == 1:
        st_to.push(st_from.pop())
        return
    
    hanoi(n-1, st_from, st_aux, st_to)
    st_to.push(st_from.pop())
    hanoi(n-1, st_aux, st_to, st_from)

print(" ** BEFORE ** ")
print(A, B, C)
hanoi(n, A, C, B)
print(" ** AFTER  ** ")
print(A, B, C)

```

     ** BEFORE ** 
    [8, 7, 6, 5, 4, 3, 2, 1] [] []
     ** AFTER  ** 
    [] [] [8, 7, 6, 5, 4, 3, 2, 1]
    

</details>

수원

<details>
<summary>접기/펼치기 버튼</summary>

```java

import java.util.Stack;

public class hanoi {
    public Stack<Integer> from;
    public Stack<Integer> mid;
    public Stack<Integer> to;

    hanoi(Integer... integers) {

        from = new Stack<>();
        mid = new Stack<>();
        to = new Stack<>();

        for (int i = integers.length - 1; i >= 0; i--)
            from.push(integers[i]);
    }

    public void print_stack(Stack<Integer> stack) {
        System.out.print("BOTTOM ->");
        for (Integer elem : stack) {
            System.out.print(" " + elem + " -> ");
        }
        System.out.println("TOP");
    }

    public void print_all() {
        System.out.print("From  |");
        print_stack(from);
        System.out.print("Mid   |");
        print_stack(mid);
        System.out.print("To    |");
        print_stack(to);
        System.out.println("");
    }

    public void solve_hanoi(Integer n, Stack<Integer> from, Stack<Integer> to, Stack<Integer> mid) {
        if (n == 1) {
            to.push(from.pop());
            return;
        }
        solve_hanoi(n - 1, from, mid, to);
        to.push(from.pop());
        solve_hanoi(n - 1, mid, to, from);
    }

    public static void main(String[] args) {
        hanoi h = new hanoi(1, 2, 3, 4, 5);
        h.print_all();
        h.solve_hanoi(5, h.from, h.to, h.mid);
        h.print_all();
    }
}

```



</details>
