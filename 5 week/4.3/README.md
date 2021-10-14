## 4.3
> 오름차순으로 정렬된 배열로부터 그 높이가 가장 낮은 이진 탐색 트리를 생성하는 알고리즘을 작성하라. 배열 내 모든 원소는 배열 내에서 유일한 값을 가진다.

김건희

<details>
<summary>접기/펼치기 버튼</summary>

[concept](https://github.com/Hamji/advanced-algorithm/blob/main/image/%EA%B9%80%EA%B1%B4%ED%9D%AC/%E1%84%82%E1%85%A9%E1%84%90%E1%85%B3%202021-10-15.pdf)
  
``` c++
  
  #include <iostream>

int arr[10] = {0,1,2,3,4,5,6,7,8,9};
using namespace std;

class Node{
  public:
    int value;
    Node *left;
    Node *right;
    Node(){
      this->value = 0;
    }
    Node(int val){
      this->value = val;
      this->left = NULL;
      this->right = NULL;
    }
};

Node* makeNode(int start, int end){
  int leng = (end + start) / 2;
  if (start == leng || end == leng)
    return new Node(arr[start]);
  Node *temp = new Node(arr[leng]);
  temp->left = makeNode(start, leng - 1);
  temp->right = makeNode(leng + 1, end);
  return temp;
}

int main() {
  Node *root = makeNode(0, 9);
  cout << root->value;
  cout << root->left->value;
  cout << root->right->value;
}
  
```

</details>
