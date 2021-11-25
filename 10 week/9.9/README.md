## 9.3
 
> 배열 A[0...n-1]에서 A[i] = i인 인덱스 i를 마술 인덱스라 정의하자.
> 정렬된 상태의 배열이 주어졌을 때, 마술 인덱스가 존재한다면 그 값을 찾는 메서드를 작성하라.
> 배열 안에 중복된 값은 없다.
> 배열에 저장되는 값에 중복이 있다면 어떻게 풀 수 있겠는가?

이혁진

<details>
<summary>접기/펼치기 버튼</summary>

```java
import java.util.Arrays;
import java.util.Random;

public class BinaryTreeProblem{

    public static void findMagicIndex(int[] arr, int start, int end){
        System.out.println(start + "\t" + end);
        if(start == 0 && end == 0)
            return;
        if(arr[(end-start)/2] == (end-start)/2){
            System.out.println((end-start)/2);
        } else if(arr[(end-start)/2] > (end-start)/2){
            findMagicIndex(arr, 0, (end-start)/2);
        }else{
            findMagicIndex(arr, (end-start)/2, end);
        }
    }

    public static void main(String[] args){
        int[] arr = new int[50];
        Random rand = new Random();

        for(int i = 0 ; i < 50 ; i++){
            arr[i] = rand.nextInt(50);
        }
        Arrays.stream(arr).sorted();
        findMagicIndex(arr, 0, arr.length);
    }
}
```
</details>