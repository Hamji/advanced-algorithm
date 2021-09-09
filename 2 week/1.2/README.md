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
