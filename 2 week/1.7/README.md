## 1.7 

> 내일 적겠습니다..

김건희
<details>
<summary>접기/펼치기 버튼</summary>

 ``` c++
  
  #include <iostream>
#include <vector>
#include <set>
#define MAX 10000

using namespace std;

vector<vector<int> > arr(MAX, vector<int>(MAX, 1));
int M, N, count;

void print(){

  for (int i = 0; i < M; i++){
    for (int j = 0; j < N; j++)
      cout << arr[i][j] << " ";
    cout << endl;
  }
}

int main() {
  
  // 초기화 부분
  cin >> M >> N >> count;
  vector<vector<int>> list(count, vector<int>(2, 0));
  for (int i = 0; i < count; i ++)
    cin >> list[i][0] >> list[i][1];
  for (int i = 0; i < count; i++)
    arr[list[i][0]][list[i][1]] = 0;
  //
  print();
  cout << endl;

  set<int> col, row;

  for (int i = 0; i < count; i++){
    col.insert(list[i][0]);
    row.insert(list[i][1]);
  }

  set<int>::iterator iter = col.begin();
  for(iter = col.begin(); iter != col.end(); iter++)
    for (int i = 0; i < N; i++)
      arr[*iter][i] = 0;

  for(iter = row.begin(); iter != row.end(); iter++)
    for (int i = 0; i < M; i++)
      arr[i][*iter] = 0;

  print();

}
  
 ```

</details>
