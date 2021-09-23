# 3.2

> `push`와 `pop`의 두 가지 연산뿐 아니라, 최솟값을 갖는 원소를 반환하는 `min` 연산을 갖춘 스택은 어떻게 구현할 수 있겠는가?  
> `push`, `pop`, 그리고 `min`은 공히 O(1) 시간에 처리되어야 한다.  
> 


김경찬
<details>
<summary>접기/펼치기 버튼</summary>
 
### 개념  
  
>Stack에 최솟값을 저장해두는 필드를 마련해두고,  
>Push를 할 때 마다 최솟값을 비교하면서 Push할 값이 최솟값보다 작을 경우 필드에 저장한다.
 ---
 
#### 문제풀이
  
``` javascript
class Stack {
  #data;
  #min;
  constructor() {
    this.#data = [];
    this.#min = null;
  }
  push(data) {
    if (this.#min == null || this.#min > data) this.#min = data;
    this.#data.push(data);
  }
  pop() {
    return this.#data.pop();
  }
  getMin() {
    return this.#min;
  }
}

let stack = new Stack();

stack.push(9999);
console.log(stack.getMin()); // 9999
stack.push(5555);
console.log(stack.getMin()); // 5555
stack.push(8888);
console.log(stack.getMin()); // 5555
stack.push(-1);
console.log(stack.getMin()); // -1

```

</details>
