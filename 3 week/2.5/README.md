## 2.5

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
    
[황규도.ipynb](https://github.com/Hamji/advanced-algorithm/blob/main/3%20week/2.5/hkd2-5.ipynb)      
    
    

김건희
<details>
<summary>접기/펼치기 버튼</summary>

![캡처](/image/김건희/add_linked_list.png)

leetcode에 비슷한 문제를 푼 적이 있는데 이때는 숫자 자리 수에 상관없이 계산이 완료되도록 보장되어야 했습니다.
링크드 리스트를 한자리 별로 계산해주고 숫자가 10을 넘어간다면 그 다음 노드에서 처리하도록 만들어 주었습니다.
    
``` c
    
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// 맨처음 조건을 안보고 했다가 나중에 조건 보니까 숫자가 뭐가 들어오던지에 상관없이 다 되어야 하더라
// longlong 이런거 안된다.
// 그래서 역순으로 들어오니까 한자리씩 계산해주고 넣어주면 된다. 그럼 다시 역순으로 들어간다 
// 10이 넘어간다면 다음 숫자로 넘겨준다. 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    int c = 0;
    
    while (l1 != NULL || l2 != NULL || c != 0){
        // 리스트가 비어있지 않다면 값을 넣어주고 아니라면 0을 넣어준다. 
        c += l1 ? l1->val : 0;
        c += l2 ? l2->val : 0;
        
        // 임시 노드 생성
        struct ListNode *temp = (struct ListNode*) malloc(sizeof(struct ListNode));
        // 임시 노드에 값 넣기
        temp->val = c % 10;
        temp->next = NULL;

        // c 가 10이 넘는다면 다음으로 넘어감
        c /= 10;
        // tail head 설정
        head = !head ? temp : head;
        // null인데 -> 썻다간 터지니깐 조건 만들어준다.
        if (tail != NULL)
            tail->next = temp;
        //tail을 끝으로 이동
        tail = temp;
        if (l1 != NULL)
            l1 = l1->next;
        if (l2 != NULL)
            l2 = l2->next;
    }
    return head;
}
    
```

</details>

