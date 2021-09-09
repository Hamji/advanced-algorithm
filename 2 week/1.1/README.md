## 1.1
>  문자열에 포함된 문자들이 전부 유일한지를 검사하는 알고리즘을 구현하라. 
>  다른 자료구조를 사용할 수 없는 상황이라면 어떻게 하겠는가?
***

건희
<details>
<summary>접기/펼치기 버튼</summary>

문자열 제한 조건 : 문자열의 값이 모두 소문자 알파벳인 경우
  
1. 배열을 사용하지 못하는 경우  
```
  배열 자료구조를 사용할 수 없는 경우에는 두 번의 for문을 사용하여 한 문자를 집어 다른 문자들과 일일히 비교하면서 중복을 검사할 수 있다. 
  따라서 해당 풀이법은 for문을 두개 이용하여 문자열을 두번 검사하므로 복잡도는 O(n^2) 이 나오게 된다.
```
2.1 배열을 사용할 수 있는 경우
```
  배열을 사용할 수 있는경우 알파벳 개수만큼 int 배열을 선언해준다. 배열 내부의 값은 0으로 초기화해준다. 그리고 처음 문자열을 돌면서 해당 알파벳이 몇번 체크되었는지 개수를 세준다. 
  for 문이 끝났다면 int 배열을 모두 검사하여 알파벳의 사용 갯수가 2 이상인 배열이 있다면 해당 문자열에 포함된 문자들이 전부 유일하지 않다는 것을 알 수 있다. 
```
  
2.2 배열을 사용하는 경우의 코드 

``` c
#include <stdio.h>

int main(int argc, char* argv[])
{
	int   alpha[26] = {0,};
	char  *s = argv[1];
	
	while (*s != '\0')
	{
		alpha[*s - 'a'] += 1;
		s++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (alpha[i] > 1)
		{
			printf("중복\n");
			return -1;
		}
	}
	printf("유일한 문자열\n");
	return 0;
}  
```
  
</details>

황규도
<details>
<summary>접기/펼치기 버튼</summary>  
	
### Concept 1:    
알파벳 하나와 소수 1개를 1:1 대응한다.	
매칭된 소수의 곱을 저장한 후, 문자열을 순회하면서 알파벳에 대응하는 소수의 나머지 값을 확인한다.  
나머지 값이 0인 경우, 대응하는 소수로 나누고 문자열이 종료될 때까지 반복한다.  
	
``` python
def solve(myStr):  
    mult_primes = sum([NthPrime(i) for i in range(26)])  
    
    for chr in myStr:  
        curr_prime = NthPrime(ord(chr) - ord("a"))   
        if mult_primes % curr_prime != 0:  
            return False  
        mult_primes //= curr_prime  
    
    return True  
```  
	
### Concept 2:
N비트를 두고, 해당 문자와 비트 1자리를 매칭한다.  
ex) a --> LSB_0, b --> LSB_1 c --> LSB_2 ... z --> LSB_25  
이후 문자가 들어오면 해당 비트의 값이 중복되었는지 확인하면 된다.  
구현은 생략
</details>  
	
김경찬
<details>
<summary>접기/펼치기 버튼</summary>  

### 개념:
원하는 문자의 범위에서 모든 문자의 숫자만큼 배열을 생성하고  
문자열의 한 글자마다 그 글자에 해당하는 정수값을 구한뒤  
배열에서 이 정수값의 인덱스에 접근해서 문자열의 존재여부를 저장한다.  
Loop를 돌면서 그 인덱스에 값에 이미 존재한다면 바로 return을 한다.  

>해답은 자바스크립트의 배열의 크기가 유동적이고, 크기를 지정할 필요가 없다는 특성을 이용  
>만약 타 언어로 작성시 아래의 기준에따라 배열을 지정해준다.
>	
>* 알파벳: 26
>* ASCII: 256
>* UNICODE: 65536
``` javascript
const isSole = (input) => {
    let tempArr = [];
    for(const letter of input){
        if (tempArr[letter.charCodeAt()])
            return false;
        else
            tempArr[letter.charCodeAt()] = true;
    }
    return true;
}
console.log(isSole("abcdefgg")); // false
console.log(isSole("가나다라마바가사아")); // false
console.log(isSole("abcdefghijk")); // true
console.log(isSole("명지대학교")); // true
```

</details>  

