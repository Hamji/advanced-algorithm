## 5.8

> 모노크롬 모니터 화면을 하나의 바이트 배열에 저장한다고 하자.
> 이때 인접한 픽셀 여덟 개를 한 바이트로 저장한다.
> 화면 폭은 w이며, 8로 나누어 떨어진다.(따라서 어떤 바이트도 두 행에 걸치지 않는다.)
> 물론, 화면 높이는 배열 길이와 화면 폭 w를 통해 유도해 낼 수 있다.
> 함수 drawHorizontalLine(byte[] screen, int width, int x1, int x2, int y)를 구현하라.
> 이 함수는 (x1, y)에서 (x2,y)로 수평선을 긋는다.

이혁진

<details>
<summary>접기/펼치기</summary>

```java
public class Monochrome {

    public static String byteToBinary(byte n){
        StringBuilder sb = new StringBuilder("00000000");

        for(int i = 0 ; i < 8 ; i++){
            if(((n>>i)&1) > 0){
                sb.setCharAt(7-i, '1');
            }
        }
        return sb.toString();
    }

    public static void drawHorizontalLine(byte[] screen, int width, int x1, int x2, int y){
        int startIndex = x1%8;
        int endIndex = x2&8;
        int changedBit = 0;
        for(int i = 0 ; i <= 8-startIndex ; i++){
            changedBit += Math.pow(2,i);
        }
        screen[((y-1) * width) + (x1/8)] = new Integer(changedBit).byteValue();
        changedBit = 0;

        for(int i = (x1/8 + 1) ; i < x2/8 ; i++){
            screen[(y-1) * width + i] = new Integer(255).byteValue();
        }

        for(int i = 1 ; i <= endIndex ; i++){
            changedBit += Math.pow(2,(8-i));
        }
        screen[((y-1) * width) + (x2/8)] = new Integer(changedBit).byteValue();

        int enter = 1;
        for(byte a : screen) {
            System.out.printf(byteToBinary(a) + " ");
            enter++;
            if(enter == width + 1) {
                enter = 1;
                System.out.println();
            }
        }
    }
    public static void main(String args[]){
        byte[] screen = new byte[800];
        for(int i = 0 ; i < screen.length ; i++){
            screen[i] = 00000000;
        }
        int width, x1, x2, y;
        width = 20;
        x1 = 10;
        x2 = 80;
        y = 2;
        drawHorizontalLine(screen, width, x1, x2, y);
    }
}
```
</details>