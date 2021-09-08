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
