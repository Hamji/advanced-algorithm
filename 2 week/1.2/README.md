## 1.2
> 널문자로 끝나는 문자열을 뒤집는 reverse(char *str) 함수를 c 나 c++로 구현하라
> 
건희
<details>
<summary>접기/펼치기 버튼</summary>

``` c
  
#include <stdio.h>
#include <string.h>

int main(int arvc, char *argv[])
{	
	char  string[100] = {};

	int   size = strlen(argv[1]);
	
	strcpy(string, argv[1]);

	for (int i = 0; i < size/2; i++)
	{
		char temp = string[i];
		string[i] = string[size - i - 1];
		string[size - i - 1] = temp;
	}

	printf("%s\n", string);
}

  
```
  
</details>

김경찬
<details>
<summary>접기/펼치기 버튼</summary>  

### 개념:
문자열의 길이를 먼저 구한다음,  
left는 문자열의 시작을, right는 문자열의 끝 위치의 주소를 넣어준다.  
이때 right의 주소를 -1 해주면 null문자를 피하면서 작업할 수 있다.  
문자열의 길이의 반만 뒤집어주면 완벽히 뒤집어지기 때문에  
left의 주소가 right의 주소보다 작을때까지만 문자열을 뒤집어주는 작업을 진행한다.
 

``` c
#include <stdio.h>

void reverse(char *str)
{
  char *left, *right;
  char temp;
  int len = 0;
  while (str[len] != 0)
  {
    len++;
  }
  left = str;
  right = str + len - 1;
  while (left < right)
  {
    temp = *right;
    *right-- = *left;
    *left++ = temp;
  }
}

int main()
{
  int len = 0;
  char input[] = "esrever";
  reverse(input);
  printf("%s", input);
  return 0;
}

```

</details>  

이재명
<details>
<summary>접기/펼치기 버튼</summary>
	
아이디어
------
- 문자열의 길이를 구한다. (길이(length)란, 문자열 내 문자의 개수를 말한다.)
- 문자열의 전반부(前半部)의 문자들에 대해 대응하는 후반부(後半部)의 문자들과 교환한다.
	
문자열의 길이를 구하는 알고리즘
------
- 문자열의 길이를 구하는 알고리즘은 `<cstring>` 표준 헤더의 `std::strlen(const char *)` 함수를 사용
- 알아두면 좋은, 표준 라이브러리에 의존하지 않고 직접 구현해야 한다는 제약사항이 있을 경우를 가정한 구현들

1. Naïve한 구현
``` C++
inline const int strlen(const char *const str)
{
    const char *ptr = str;
    while ( *ptr )
    {
        ++ptr;
    }
    return ptr - str;
}
```
	
2. 성능을 중시한 구현 ([참고 문헌 - Bit Twiddling Hacks](https://graphics.stanford.edu/~seander/bithacks.html#ZeroInWord))
  - `std::strlen` 함수를 이렇게 구현한 C/C++ 컴파일러들도 많음
``` C++
#include <cstdint>
using namespace std;

// 32비트 정수에 0x00 바이트가 존재하는가? (비트 핵)
inline const int32_t u32_contain_zero(const int32_t val)
{
    // 각 바이트에 대해 0x01을 뺀 뒤, 원래 값에 0x80 비트가 있었던 경우를 제외시키고,
    // 0x00 바이트가 있는 경우 0x01을 빼면 내림(빌림)이 발생한다는 성질을 이용하여,
    // 0x80 비트를 테스트해 0x00 바이트를 검출
    return ( val - 0x01010101 ) & ~val & 0x80808080;
}

// strlen_perf 구현 (성능 최적화 버전)
inline const int strlen_perf(const char *const str)
{
    const char *ptr = str;
    while ( !u32_contain_zero(*(const int32_t *)ptr) )
    {
        ptr += 4;
    }
    while ( *ptr )
    {
        ++ptr;
    }
    return ptr - str;
}
```

두 값을 뒤바꾸는 알고리즘
------
- 두 값을 뒤바꾸는 알고리즘은 `<algorithm>` 표준 헤더의 `std::swap(char &, char &)` 함수를 사용
- 표준 라이브러리에 의존하지 않고 직접 구현해야 한다는 제약사항이 있을 경우
``` C++
template <class T>
inline void swap(T &a, T &b)
{
    const T tmp = a;
    a = b;
    b = tmp;
}
```
	
구현
------
- 언어: C++

``` C++
#include <cstring>
#include <algorithm>
using namespace std;

void reverse(char *str)
{
    const size_t len        = strlen(str);
    const size_t final_pos  = len - 1;
    const size_t half_pos   = len / 2;
    for ( size_t i = 0; i < half_pos; ++i )
    {
        swap(str[i], str[final_pos - i]);
    }
}
```
</details>
