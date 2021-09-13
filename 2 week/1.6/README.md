## 1.6

> 이미지를 표현하는 NxN 행렬이 있다. 이미지의 각 픽셀은 4바이트로 표현된다.
> 이때, 이미지를 90도 회전시키는 메서드를 작성하라. 
> 부가적인 행렬을 사용하지 않고서도 할 수 있겠는가?

건희
<details>
<summary>접기/펼치기 버튼</summary>


``` c
  
#include <stdio.h>

#define MAX 10

int arr[MAX][MAX] = {0, };

// 출력 함수
void print()
{
	printf("======print matrix======\n");
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
			printf("%3d ", arr[i][j]);
		printf("\n");
	}
	printf("======  END  ======\n");
}
// 회전 함수
void rotate()
{
	for (int i = 0; i < MAX / 2; i++)
	{
		for (int j = i; j < MAX - 1 - i; j++)
		{
			int temp = arr[i][j];
			arr[i][j] = arr[MAX - 1 - j][i];
			arr[MAX - 1 - j][i] = arr[MAX - 1 - i][MAX - 1 - j];
			arr[MAX - 1 - i][MAX - 1 - j] = arr[j][MAX - 1 - i];
			arr[j][MAX - 1 - i] = temp;
		}
	}
}

int main()
{
	int n = 1;

	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			arr[i][j] = n++;

	print();
	rotate();
	print();
}


```


</details>
	
	
	
김경찬
<details>
<summary>접기/펼치기 버튼</summary>  

### 개념:
1. 임시로 상우 값을 저장해둔다.
2. 상우에 상좌 값을 대입한다.
3. 상좌에 하좌 값을 대입한다.
4. 하좌에 하우 값을 대입한다.
5. 하우에 1번에서 저장한 값을 대입한다.

열은 N-1 까지 반복하고  
행은 N/2 까지 반복한다.
 
``` javascript
const problem = [
  ["1", "2", "3", "4", "5"],
  ["1", "2", "3", "4", "5"],
  ["1", "2", "3", "4", "5"],
  ["1", "2", "3", "4", "5"],
  ["1", "2", "3", "4", "5"],
];
const rotate = (image) => {
  const nNum = image.length - 1;
  let temp = "";
  image.some((row, rowIdx) => {
    if (rowIdx >= 2) return true;
    row.some((col, colIdx) => {
      if (colIdx >= rowIdx) {
        if (colIdx > nNum - rowIdx - 1) return true;
        temp = image[colIdx][nNum - rowIdx];
        image[colIdx][nNum - rowIdx] = image[rowIdx][colIdx]; // 1
        image[rowIdx][colIdx] = image[nNum - colIdx][rowIdx];
        image[nNum - colIdx][rowIdx] = image[nNum - rowIdx][nNum - colIdx];
        image[nNum - rowIdx][nNum - colIdx] = temp;
      }
    });
  });
};
rotate(problem);
console.log(problem);
```
</details>

이재명
<details>
<summary>접기/펼치기 버튼</summary>
	
아이디어
------
![예시 그림](https://i.postimg.cc/0jg1rg0H/table.png)
	
그림에서 알 수 있듯이,
- N이 짝수일 때는 0 ≤ 행 < N/2, 0 ≤ 열 < N/2에 해당하는 왼쪽-위 4사분면에 대해서 대응하는 4개의 셀을 시프트하면 된다.
- N이 홀수일 때는 0 ≤ 행 ≤ N/2, 0 ≤ 열 < N/2에 해당하는 왼쪽-위 4사분면에 대해서 대응하는 4개의 셀을 시프트하면 된다.
	
구현
------
- 언어: Modern C++ (C++11 이상)

``` C++
#include <cstdint>
using namespace std;

inline void rotate_cell(int32_t *const arr, const int n, const int row, const int col)
{
    int cr = row, cc = col;
    const int32_t backup = arr[row * n + col];

    for ( int i = 0; i < 3; ++i )
    {
        const int nr = n - 1 - cc, nc = cr;
        arr[cr * n + cc] = arr[nr * n + nc];
        cr = nr, cc = nc;
    }

    arr[cr * n + cc] = backup;
}

void rotate(int32_t *const arr, const int n)
{
    const int n_half = n / 2;
    
    if ( n % 2 == 0 )
    {
        for ( int r = 0; r < n_half; ++r )
        {
            for ( int c = 0; c < n_half; ++c )
            {
                rotate_cell(arr, n, r, c);
            }
        }
    }
    else
    {
        for ( int r = 0; r <= n_half; ++r )
        {
            for ( int c = 0; c < n_half; ++c )
            {
                rotate_cell(arr, n, r, c);
            }
        }
    }
}
```
</details>
