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
 
 </details>

김경찬
<details>
<summary>접기/펼치기 버튼</summary>  

### 개념1:
M*N행렬을 0,0부터 M,N까지 하나씩 순회하면서 0인 원소를 찾는다.
 
 ``` javascript
 let count = 0; // 몇번만에 찾는지 구하기위해
const problem = [
  [1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1],
  [1, 1, 1, 1, 0],
];

const setColZero = (problem, col) => problem.forEach((e) => (e[col] = 0)); // 열을 0으로
const setRowZero = (problem, row) =>
  problem[row].forEach((e, i) => (problem[row][i] = 0)); // 행을 0으로

const numCol = problem[0].length;
const numRow = problem.length;
let numElement = numCol * numRow; // M*N 원소의 수 구하기

for (let i = 0; i < numElement; i++) {
  count++;
  if (problem[Math.floor(i / numRow)][i % numCol] == 0) {
    setRowZero(problem, Math.floor(i / numRow));
    setColZero(problem, i % numCol);
    break;
  }
}
console.log(count, problem);
 
 ``` 
 
### 개념2:
M*N 행렬에서 원소를 랜덤하게 접근해서 0인지 아닌지 판별한다.
최상의 경우에서 한번에 해결하지만 최악의 경우 무한으로 간다.
유일한 난수를 생성하는 알고리즘을 사용하면 해결되지만 너무 복잡해지지 않을까?

``` javascript
let count = 0; // 몇번만에 찾는지 구하기위해
const problem = [
  [1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1],
  [1, 1, 1, 0, 1],
  [1, 1, 1, 1, 1],
];

const setColZero = (problem, col) => problem.forEach((e) => (e[col] = 0)); // 열을 0으로
const setRowZero = (problem, row) =>
  problem[row].forEach((e, i) => (problem[row][i] = 0)); // 행을 0으로

const numCol = problem[0].length;
const numRow = problem.length;
let randCol, randRow;

while (1) {
  randCol = Math.floor(Math.random() * numCol);
  randRow = Math.floor(Math.random() * numRow);
  count++;
  if (problem[randRow][randCol] == 0) {
    setRowZero(problem, randRow);
    setColZero(problem, randCol);
    break;
  }
}

console.log(count, problem);

```
 ### 개념3:
 개념2에서 유일한 난수를 뽑아내는 버전

``` javascript
 // 난수생성은 O(1)
let count = 0; // 몇번만에 찾는지 구하기위해
const problem = [
  [1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1],
  [1, 1, 1, 1, 1],
  [1, 1, 1, 0, 1],
  [1, 1, 1, 1, 1],
];
const numCol = problem[0].length;
const numRow = problem.length;
let numElement = numCol * numRow; // M*N 원소의 수

const randomArray = [...Array(numElement)].map((v, i) => i + 1); // 1~원소갯수 배열
const setColZero = (problem, col) => problem.forEach((e) => (e[col] = 0)); // 열을 0으로
const setRowZero = (problem, row) =>
  problem[row].forEach((e, i) => (problem[row][i] = 0)); // 행을 0으로
const getRand = () =>
  randomArray.splice(Math.floor(Math.random() * randomArray.length), 1)[0]; // 유일한 난수 꺼내기

let random;
while (1) {
  random = getRand();
  count++;
  if (problem[Math.ceil(random / numRow) - 1][random % numCol] == 0) {
    setRowZero(problem, Math.ceil(random / numRow) - 1);
    setColZero(problem, random % numCol);
    break;
  }
}

console.log(count, problem);
```

</details>  
