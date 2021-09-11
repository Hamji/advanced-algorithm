##2.5

>연결 리스트로 표현된 두 개의 수가 있다고 하자.
> 리스트의 각 노드는 해당 수의 각 자릿수를 표현한다.
> 이때 자릿수들은 역순으로 배열되는데, 1의 자릿수가 리스트의 맨 앞에 오도록 배열된다는 뜻이다.
> 이 두 수를 더하여 그 합을 연결 리스트로 반환하는 함수를 작성하라.

---

혁진

<details>
<summary>접기/펼치기 버튼</summary>

```java
import java.util.LinkedList;

public class Week2_5 {
    public static LinkedList<Integer> createLinkedList(int arr[]){
        LinkedList<Integer> list = new LinkedList();

        for(int atom : arr){
            list.add(atom);
        }

        return list;
    }

    public static int listToInteger(LinkedList<Integer> list){
        int dec = 1;
        int result = 0;
        for(int atom : list){
            result += atom * dec;
            dec *= 10;
        }
        return result;
    }

    public static void problem(LinkedList firstList, LinkedList secondList){
        LinkedList<Integer> resultList = new LinkedList();
        int firstNum, secondNum, resultNum;
        int dec = 10;
        firstNum = listToInteger(firstList);
        secondNum = listToInteger(secondList);

        resultNum = firstNum + secondNum;

        for(int i = 0 ; i < (int)(Math.log10(resultNum) + 1) ; i++){
            resultList.add((resultNum%dec)/(dec/10));
            resultNum -= resultNum%dec;
            dec *= 10;
        }
        System.out.println("First Number : " + firstNum);
        System.out.println("Second Number : " + secondNum);
        System.out.println("Result : " + resultList);
    }

    public static void main(String args[]){
        int[] firstNum, secondNum;
        LinkedList<Integer> firstList, secondList;
        firstNum = new int[]{7, 1, 6};
        secondNum = new int[]{5,9,2};

        firstList = createLinkedList(firstNum);
        secondList = createLinkedList(secondNum);

        problem(firstList, secondList);
    }
}
```

</details>