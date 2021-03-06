## 6.3

> 5리터 물병과 3리터 물병이 있다. 물은 무제한으로 주어지지만 계량컵 같은 것은 없다.  
> 두 물병만 사용해서 4리터의 물을 계량하려면 어떻게 하면 되겠는가?  
> 물병의 형태가 좀 괴상해서, 정확히 ‘절반만’ 물을 담는 것 따위는 불가능하다.

이재명
<details>
<summary>접기/펼치기 버튼</summary>
	
아이디어
------
- 3리터를 채운다.
  - 3L (3리터), 0L (5리터)
- 3리터 물을 5리터에 붓는다.
  - 0L (3리터), 3L (5리터)
- 3리터를 채운다.
  - 3L (3리터), 3L (5리터)
- 3리터 물을 5리터가 가득 찰 때까지 붓고 남는 건 남겨둔다.
  - 1L (3리터), 5L (5리터)
- 5리터 물을 전부 버리고 3리터 물을 5리터에 붓는다.
  - 0L (3리터), 1L (5리터)
- 3리터를 채운다.
  - 3L (3리터), 1L (5리터)
- 3리터 물을 5리터에 붓는다.
  - 0L (3리터), 4L (5리터)

풀이 증명
------
- 위 풀이는 3리터에 물을 세 번 채우므로 총 9리터의 물이 든다.
- 들어가는 물의 양을 더 줄일 수는 없을까? 다른 말로는, 이것이 최선인가?
- 증명
```
최선이다. 물을 채우는 행위는 3리터 물병과 5리터 물병에 대해서만 할 수 있으므로,  
들어가는 물의 양은 수학적으로 3a + 5b (a, b는 모두 0 이상의 정수) 이다.
3L의 배수와 5L의 배수로 4L의 차이를 낼 수 있는 가장 물의 양이 적은 경우로
1L(6L - 5L)와 5L, 그리고 지금처럼 5L와 9L가 있는데,
1L와 5L는 3L를 채우고 5L로 옮기고 3L를 채운 뒤 5L가 가득찰 때까지 5L로 옮겨
1L를 남긴 뒤, 5L에서 1L만큼만 물을 버려낼 수 있다면 6L의 물 만으로도 이 문제를 풀 수 있지만
주어진 두 개의 병 가지고는 그렇게 할 수 있는 방법이 없다.
따라서 풀이처럼 5L와 9L의 차이를 이용하여 푼, 물 9L가 드는 풀이가 최선이다.
	
수학적으로 엄밀한 느낌이 부족한 것 같으므로, 경우의 수를 전수 조사해보자.
9L보다 적게 물이 들어가는 경우의 수는 3a + 5b에서 3L, 5L, 6L, 8L 네 가지 경우 뿐이다.
1. 3L는 계량하고자 하는 4L보다 적은 양이므로 안된다.
2. 5L는 3리터 물병과 5리터 물병 가지고는 4L의 차이를 만들어낼 수 없다.
3. 6L는 방법이 없음을 이미 위에서 설명하였다.
4. 8L는 3리터 물병과 5리터 물병을 모두 물로 채웠을 때의 상황인데, 아무것도 할 수 없다.
이상의 논의에서, 이 문제를 풀기 위해서는 최소 9L의 물이 필요하다고 결론을 내릴 수 있으므로 최선의 풀이이다.
```
</details>
