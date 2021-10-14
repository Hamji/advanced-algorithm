## 4.9

>각 노드에 어떤 값이 저장되어 있는 이진 트리 하나와 값n이 주어졌을 때, n과 같은 값을 갖는 모든 노드를 찾아라.
> 어떤 경로의 값은 그 경로에 포함된 모든 노드의 값의 합이며, 경로는 트리 내의 아무 위치에서나 시작하고 끝날 수 있다.
 

이혁진
<details>
<summary>접기/펼치기 버튼</summary>

```java
import java.util.*;

public class BinaryTreeProblem {
    public static BinaryTreeProblem tree = new BinaryTreeProblem();
    public static Node root;
    public static List<Integer> startIndexList = new ArrayList<>();
    public static List<Integer> endIndexList = new ArrayList<>();

    BinaryTreeProblem(){
        root = null;
    }

    static class Node {
        int key, index;
        Node left, right, parent;

        public Node(Node parent, int item, int index) {
            this.parent = parent;
            this.index = index;
            key = item;
            left = right = null;
        }
    }

    public static int printPath(Node node, int target, int checkVal, String str, int endIndex){
        checkVal += node.key;
        int temp;
        if(checkVal == target) {
            if(startIndexList.contains(node.index)) {
                temp = startIndexList.indexOf(node.index);
                if(endIndex == endIndexList.get(temp))
                    return 0;
            }else{
                startIndexList.add(node.index);
                endIndexList.add(endIndex);
                System.out.println(str + node.key);
                return 0;
            }
        }else{
            str += node.key + " => ";
            return printPath(node.parent, target, checkVal, str, endIndex);
        }
        return 0;
    }

    public static void breadthFirstSearch(Node node, int target, int sum){
        if(root == null) return;

        sum += node.key;

        if(sum == target) {
            printPath(node, target, 0, "", node.index);
            if(node.left != null)
             breadthFirstSearch(node.left, target, 0);
            if(node.right != null)
             breadthFirstSearch(node.right, target, 0);
        }else{
            if(node.left != null){
                breadthFirstSearch(node.left, target, sum);
                breadthFirstSearch(node.left, target, 0);
            }
            if(node.right != null){
                breadthFirstSearch(node.right, target, sum);
                breadthFirstSearch(node.right, target, 0);
            }
        }
    }


    public static void createBinaryTree(Node node, int value){
        Random rand = new Random();
        int temp = rand.nextInt(2);

        switch (temp){
            case 0:
                if(node.left == null){
                    node.left = new Node(node, value, (node.index*2));
                }else{
                    createBinaryTree(node.left, value);
                }
                break;
            case 1:
                if(node.right == null){
                    node.right = new Node(node, value, ((node.index*2)+1));
                }else{
                    createBinaryTree(node.right, value);
                }
                break;
        }
    }

    public static void main(String args[]){

        Random rand = new Random();
        tree.root = new Node(null, rand.nextInt(100), 1);
        System.out.println("root Value : " + root.key);
        for(int i = 0 ; i < 100 ; i++){
            createBinaryTree(tree.root, rand.nextInt(100));
        }

        breadthFirstSearch(root, rand.nextInt(100), 0);
    }
}
```

</details>