# 4.8

> 두 개의 큰 이진 트리 T1, T2가 있다고 하자. T1에는 수백만 개의 노드가 있고,
> T2에는 수백 개 정도의 노드가 있다. T2가 T1의 하위 트리인지 판별하는 알고리즘을
> 만들라


김경찬
<details>
<summary>접기/펼치기 버튼</summary>
 
### 개념  
  
> T1의 모든 노드의 In Order 값을 배열에 저장하고, T2의 In Order값이 이 배열에 포함되는지 알아보면 된다.
 
 ---
 
#### 문제풀이
<img width="800" src="https://user-images.githubusercontent.com/8155815/137364708-5ac882c1-c7fa-4ea7-bd40-e0826ca2c88a.png">

``` javascript
const inOrder = (tree, idx) => {
  const result = [];
  function traverse(tree, idx) {
    if (tree[idx]) {
      traverse(tree, idx * 2);
      result.push(tree[idx]);
      traverse(tree, idx * 2 + 1);
    }
  }
  traverse(tree, idx);
  return result.join(">");
};

const isSubTree = (sub, target) => {
  // 트리의 모든 InOrder값을 DP로 구한다.
  const traverseArray = [];
  for (let i = target.length - 1; i > 0; i--) {
    if (!target[i * 2] && !target[i * 2 + 1]) {
      // 현재 노드가 Leaf일 경우
      traverseArray[i] = target[i];
    } else if (target[i * 2] || target[i * 2 + 1]) {
      // 현재 노드가 Leaf가 아닐 경우
      traverseArray[i] =
        (traverseArray[i * 2] ? traverseArray[i * 2] + ">" : "") +
        target[i] +
        (traverseArray[i * 2 + 1] ? ">" + traverseArray[i * 2 + 1] : "");
    }
  }
  return traverseArray.includes(inOrder(sub, 1));
};

const T1 = [null, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18];
const T2 = [null, 3, 6, 7, 12, 13, 14, 15];

// console.log(inOrder(T2, 1)); // 12>6>13>3>14>7>15
console.log(isSubTree(T2, T1));
/*
[
  <1 empty item>,
  '16>8>17>4>18>9>2>10>5>11>1>12>6>13>3>14>7>15',
  '16>8>17>4>18>9>2>10>5>11',
  '12>6>13>3>14>7>15',
  '16>8>17>4>18>9',
  '10>5>11',
  '12>6>13',
  '14>7>15',
  '16>8>17',
  '18>9',
  10,
  11,
  12,
  13,
  14,
  15,
  16,
  17,
  18
]
*/

```


</details>
