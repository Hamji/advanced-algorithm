## 2.4

> x값을 갖는 노드를 기준으로 연결리스트를 나누는 코드를 작성하라.
> x보다 작은 값을 갖는 노드가 x와 같거나 더 큰 값을 갖는 노드들보다 앞쪽에 오도록 하면 된다.

---

혁진

<details>
<summary>접기/펼치기 버튼</summary>

``` java
import java.util.LinkedList;

public class Week2_4 {
public static LinkedList<Integer> createLinkedList(int linkedList[]){
LinkedList<Integer> list = new LinkedList();

        for(int atom : linkedList){
            list.add(atom);
        }
        return list;
    }

    public static void problem(LinkedList<Integer> list, int x){
        int temp, i;
        for(i = 0; list.get(i) != x ; i++){
            if(list.get(i) > x){
                temp = list.get(i);
                list.remove(i);
                list.addLast(temp);
                i--;
            }
        }
        while(i < list.size()){
            if(list.get(i) < x){
                temp = list.get(i);
                list.remove(i);
                list.addFirst(temp);
                i--;
            }
            i++;
        }

        System.out.println(list);
    }

    public static void main(String args[]){
        int[] linkedList = {7,4,5,6,8,9,1,2,3,3,4,5,6,7,8,9};
        LinkedList<Integer> list;

        list = createLinkedList(linkedList);
        for(int i = 0 ; i < list.size() ; i++) {
            System.out.println("Target : " + list.get(i));
            problem(list, list.get(i));
        }
    }
}

```

</details>