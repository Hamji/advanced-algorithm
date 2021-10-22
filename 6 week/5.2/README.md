## 5.2 

> 0 과 1 사이의 실수가 double 타입의 입력으로 주워졌을 때, 그 값을 이진수 형태로 출력하는 코드를 작성하여라. 
> 길이가 32 이하 문자열로 출력될 수 없는 경우에는, ERROR를 대신 출력하자

김건희

<details>
<summary>접기/펼치기 버튼</summary>

``` python

value = 0.625

if not (0 < value < 1):
  print("ERROR")
  exit()

result = ""
while(value > 0):
  if len(result) >= 32:
    print("ERROR: TOO LONG")
    exit()

  r = value * 2;
  if r >= 1: 
    result += "1"
    value = r -1
  else :
    result += "0"
    value = r
  #print(result)
  
print(result)
  


```

</details>

이재명
<details>
<summary>접기/펼치기 버튼</summary>
	
아이디어
------
- 문제에서 입력이 double 타입의 실수(實數, real number) 입력이라 명시하였다.
- 따라서 입력값은 IEEE 754 배정도(倍精度) 부동소수점(double-precision floating point)이다.
- 그러므로 IEEE 754 배정도 부동소수점의 구조를 이용하면 느린 FPU(floating point unit) 연산에 의존하지 않고 효율적으로 풀 수 있다.
  - y = fabs(x)도 포인터 접근으로 MSB를 0으로 설정하는 방식으로 구현하면 매우 빠르다.

구현
------
- 언어: Modern C++ (C++11 이상)

``` C++
#include <cstdio>
#include <cstdint>

using namespace std;

void print_binary(double x)
{
    // zero check
    if ( !( *(uint64_t *)&x << 1 ) )
    {
        puts("0");
        return;
    }

    int         exponent_abs    = -( ( (int16_t *)&x )[3] >> 4 ) + 1023;
    uint64_t    mantissa        = 0x8000000000000000ULL | *(uint64_t *)&x << 11; // mantissa with implicit bit

    // check the exponent field
    if ( exponent_abs > 30 )
    {
        fprintf(stderr, "ERROR\n");
        return;
    }

    const int       possible_digits = 31 - exponent_abs;
    const uint64_t  error_checker   = ~uint64_t(0) >> possible_digits;
    
    // check the mantissa field
    if ( mantissa & error_checker )
    {
        fprintf(stderr, "ERROR\n");
        return;
    }

    // print the first digit
    if ( !exponent_abs )
    {
        putchar('1');
        mantissa <<= 1;
    }
    else
    {
        putchar('0');
        --exponent_abs;
    }

    // if there's still something to print out
    if ( mantissa )
    {
        // print a dot character
        putchar('.');
        while ( exponent_abs-- )
        {
            putchar('0');
        }
        do
        {
            putchar(( int64_t(mantissa) < 0 ) | '0');
        } while ( mantissa <<= 1 );
    }

    // print a newline character
    putchar('\n');
}

int main(void)
{
    print_binary(0.0);      // 0
    print_binary(0.25);     // 0.01
    print_binary(0.3);      // ERROR
    print_binary(0.5);      // 0.1
    print_binary(0.625);    // 0.101
    print_binary(1.0);      // 1

    return 0;
}
```
</details>
