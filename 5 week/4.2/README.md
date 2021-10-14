## 4.2

> 주어진 유향 그래프(directed graph) 에서 특정한 두 노드 간에 경로가 존재하는 지를 판별하는 알고리즘을 구현하여라.

김경찬
<details>
<summary>접기/펼치기 버튼</summary>
 
### 개념  
  
> 첫번째 노드를 시작으로 너비우선 탐색을 해서 두번째 노드를 찾아내면 된다.
 
 ---
 
#### 문제풀이
<img width="356" src="https://user-images.githubusercontent.com/8155815/137372818-fe5b0c8a-0503-41e3-bacf-4e919f5dd06f.png">

``` javascript
class DirectedGraph {
  constructor() {
    this.edges = {};
  }
  //정점을 추가하는 함수
  addVertex(vertex) {
    this.edges[vertex] = {};
  }
  //간선을 추가하는 함수
  addEdge(originVertex, destVertex, weight) {
    // 시작 정점, 도착 정점, 가중치
    if (weight === undefined) {
      weight = 0;
    }
    this.edges[originVertex][destVertex] = weight;
  }
  hasRoute(originVertex, destVertex) {
    const visitedList = {};
    const nextList = []; // queue
    let nowVertex;
    let result;
    nextList.push(originVertex);
    Object.keys(this.edges).forEach((e) => {
      // 방문상태 초기화
      visitedList[e] = false;
    });
    //너비우선탐색
    while (nextList.length > 0) {
      nowVertex = nextList.shift();
      result = Object.keys(this.edges[nowVertex]).some((adjacency) => {
        if (visitedList[adjacency] == false) {
          if (adjacency == destVertex) {
            return true;
          } else {
            nextList.push(adjacency);
          }
        }
      });
      if (result) return true;
      visitedList[nowVertex] = true;
    }

    return false;
  }
}

let graph = new DirectedGraph();
graph.addVertex("a");
graph.addVertex("b");
graph.addVertex("c");
graph.addVertex("d");
graph.addVertex("e");
graph.addEdge("a", "b", 1);
graph.addEdge("a", "c", 1);
graph.addEdge("a", "e", 1);
graph.addEdge("c", "d", 1);
console.log(graph.hasRoute("a", "d")); // true
console.log(graph.hasRoute("c", "a")); // false

```


</details>
