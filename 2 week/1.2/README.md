## 1.2
#### 널 문자로 끝나는 문자열을 뒤집는 reverse(char *str) 함수를 c 나 c++로 구현하라
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
