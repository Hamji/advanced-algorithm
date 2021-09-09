## 1.3
> 문자열 두개를 입력으로 받아 그중 하나 다른 하나의 순열인지 판별하는 메서드를 작성하라.
***
건희
<details>
<summary>접기/펼치기 버튼</summary>

문자열 제한 조건 : 소문자
  
``` c
  
#include <stdio.h>

int main(int argc, char* argv[])
{
	char *s1, *s2;
	int	 alpha[26] = {0,};

	s1 = argv[1];
	s2 = argv[2];
	
	while (*s1 != '\0')
	{
		alpha[*s1 - 'a']++;
		s1++;
	}

	while (*s2 != '\0')
	{
		alpha[*s2 - 'a']--;
		s2++;
	}
	
	for (int i = 0; i < 26; i++)
		if (alpha[i] < 0)
		{
			printf("False\n");
			return -1;
		}
	
	printf("True\n");
	return 0;
}

  
```
  
</details>

황규도
<details>
<summary>접기/펼치기 버튼</summary>
	
``` python

def solve(a, b):
    a = sorted(a)
    b = sorted(b)
    return a == b
	
```
		    
</details>
