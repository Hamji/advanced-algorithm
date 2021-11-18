## 8.6

문제
------
직소<b><sup>jigsaw</sup></b> 퍼즐을 구현하라. 자료구조를 설계하고, 퍼즐을 푸는 알고리즘을 설명하라.  
주어진 두 개의 조각이 들어맞는지를 판별하는 `fitsWith` 메서드가 주어진다고 가정하도록 하라.

풀이
------

이재명
<details>
<summary>접기/펼치기 버튼</summary>

자료구조
------

1. 직소 퍼즐 조각을 표현하는 자료구조 (8비트 크기)
```C++
#pragma pack(1)
struct JigsawPiece
{
    // 각각의 값은: -1 오목, 0 평평, +1 볼록
    signed char east:2;
    signed char west:2;
    signed char south:2;
    signed char north:2;
};
#pragma pack()
```

2. 12가지 상태에 대해서 bitset으로 표시
```C++
std::bitset<W*H> east[3];
std::bitset<W*H> west[3];
std::bitset<W*H> south[3];
std::bitset<W*H> north[3];
```

알고리즘
------
- 기본적으로 8-퀸 문제의 해법과 마찬가지로 backtracking 방법을 이용한다.
- W x H 크기의 직소 퍼즐판이 있고 (W * H) 개의 직소 퍼즐 조각이 있다고 하자.
1. 좌상부터 하나씩 퍼즐 조각을 놓아본다.
  - 놓아진 퍼즐 조각은 별도의 bitset인 chosen로 관리한다. (0: 미선택, 1: 선택)
```C++
std::bitset<W*H> chosen;
```
  - 놓을 퍼즐 조각은 상하좌우에 인접한 경계를 고려하여 east[e], west[w], south[s], north[n], ~chosen의 비트열을 and 연산하여 적합한 조각 후보들을 찾아낸다.
  - 더 이상 적합한 후보가 없으면 이전 조각으로 돌아간다.
2. 알고리즘 종료. 모든 자리가 채워지면 그것이 해답이며, 채워지지 않았으면 해답이 없는 퍼즐이다.
 
</details>
