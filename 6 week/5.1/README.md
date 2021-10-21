## 5.1 

> 두 개의 32비트 수 N과 M이 주어지고 ,비트 위치 i와 j가 주어졌을 때, M을 N에 삽입하는 메서드를 구현하라. M은 N의 j번재 비트에서 시작하여 i번
> 째 비트에서 끝나야 한다. j 번째 비트에서 i 번째 비트까지에는 M을 담기에 충분한 공간이 있다고 가정한다. 다시 말해, M = 10011라면, 
> j = 3 는 i는 2여서 M을 삽입할 수 있는 상황은 생기지 않는다고 봐도 좋다는 것이다.

#### - 예
```
입력 : N 10000000000 M = 10011, i = 2, j = 6
출력 : N  = 10001001100
```

김건희

<details>
<summary>접기/펼치기 버튼</summary>

``` c

#include <stdio.h>

int makeBit(int n, int m, int i, int j){
  int ones = ~0;

  int left = ones << (j + 1);
  int right = ((1 << i) -1);

  int mask = left | right;

  int result = n & mask;
  m = m << i;

  return result | m;
}

int main(void) {
  int result = makeBit(1024, 19, 2, 6);
  for (int i = 10; i >= 0; --i) { //8자리 숫자까지 나타냄
        int temp = result >> i & 1;
        printf("%d", temp);
  }

}


```

</details>
