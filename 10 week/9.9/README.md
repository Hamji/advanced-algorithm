## 9.9

> 8x8 체스판상에 여덟개의 퀸을 놓는 모든 가능한 방법을 출력하는 알고리즘을 작성하라.  
> 퀸들 가운데 어떤 것도 같은 행이나 열, 혹은 같은 개각선상에 놓이면 안 된다.  
> 여기서 '대각선'은 모든 대각선을 의미하는 것으로, 체스판을 양분하는 대각선 두 개로 한정하지 않는다.  

김경찬

<details>
<summary>접기/펼치기 버튼</summary>

```javascript
const queens = [];
const numOfQueen = 8;
let solutionNum = 1;

function solver(row) {
  // 퀸을 놓지 못할 경우 가지치기
  if (!verify(row)) return;

  // 8개의 퀸을 모두 놓았으면 출력
  if (row == numOfQueen) {
    console.log(`-----Soltuion ${solutionNum++}-----`);
    queens.forEach((e, i) => {
      let buffer = "";
      for (let i = 0; i < numOfQueen; i++) {
        buffer += e == i ? "ㅁ" : "ㅁ";
      }
      console.log(buffer);
    });
    return;
  }

  for (let col = 0; col < numOfQueen; col++) {
    queens[row + 1] = col;
    if (solver(row + 1)) return;
  }
}

function verify(row) {
  for (let i = 0; i < row; i++) {
    /* 한 행에는 하나의 퀸만 존재한다.
      즉, 퀸들이 같은 열에 있는지만 검사하고,
      대각선에도 있는지만 검사한다.
      0행부터 새로 놓을 행까지만 검사하면 된다.
      */
    if (
      queens[row] == queens[i] ||
      row - i == Math.abs(queens[row] - queens[i])
    ) {
      return false;
    }
  }
  return true;
}

solver(0);
```

</details>
