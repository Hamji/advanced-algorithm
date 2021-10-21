## 5.6

> 주어진 정수의 짝수 번째 비트의 값과 홀수 번째 비트의 값을 바꾸는 프로그램을 작성하라.  
> (예: 0번째 비트와 1번째 비트를 바꾸고, 2번째 비트와 3번째 비트를 바꾸고... 이런 식으로.)  
>
> 가능한 한 적은 수의 명령어(instruction)가 실행되도록 해야 한다.  

이재명
<details>
<summary>접기/펼치기 버튼</summary>
	
아이디어
------
<img src="https://i.postimg.cc/q7N2SMPb/solution.png">

구현
------
- 언어: Modern C++ (C++11 이상)
- https://ideone.com/Vc8CYZ

``` C++
#include <cstdio>
#include <cstdint>
#include <cinttypes>

using namespace std;

int main(void)
{
    uint64_t num;
    printf("Enter an integer: ");
    scanf("%" SCNu64, &num);
    printf("\n");
    
    printf("%" PRIu64 "\n", 
        ( num & 0xAAAAAAAAAAAAAAAALL ) >> 1 | 
        ( num & 0x5555555555555555LL ) << 1 );
    return 0;
}
```
</details>
