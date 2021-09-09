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
	
김경찬
<details>
<summary>접기/펼치기 버튼</summary>  

### 개념:
배열을 유니코드의 갯수만큼 0으로 채우고  
주어진 문자열을 한 글자씩 순회하면서 그 글자의 유니코드로 배열 Idx에 접근한다.  
그리고 그 값을 1 증가 시킨다.  
두 배열이 같은지 확인한다  
 

``` javascript
const isSame = (input1, input2) => {
  const array1 = new Array(65536).fill(0),
    array2 = new Array(65536).fill(0);
  if (input1.length != input2.length) return false;
  [...input1].forEach((e, i) => {
    array1[input1[i].charCodeAt()]++;
    array2[input2[i].charCodeAt()]++;
  });
  return !array1.some((e, i) => {
    return array1[i] != array2[i];
  });
};

console.log(isSame("명지대학교", "대지명")); // 글자수다름
console.log(isSame("명지대학교", "학대지명교")); // 같은순열
console.log(isSame("Coffee", "efefCo")); // 같은순열
console.log(isSame("띵지대학교", "학대지명교")); // 다른순열
```
