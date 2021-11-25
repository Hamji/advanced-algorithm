## 9.7

> 이미지 편집 프로그램에서 흔히 쓰이는 '영역칠하기' 함수를 구현하라.
> 즉, 색상이 칠해진 이차원 배열로 표현되는 스크린과 그 스크린 상의 한 지점, 그리고 새로운 색상이 주어졌을 때,
> 주어진 지점을 포함하는 영역의 생상을 원래 색상에서 새로운 색상으로 변경하는 함수를 작성하라.

이혁진

<details>
<summary>접기/펼치기 버튼</summary>

```java
import java.util.Random;

public class BinaryTreeProblem {

    public static String[][] screen;
    public static int X = 4;
    public static int Y = 10;

    public static void paintFill(int x, int y, String color, String curColor){
        if(curColor == screen[y][x]) {
            screen[y][x] = color;
            checkScreen();
            if(x > 0)
                paintFill(x - 1, y, color, curColor);
            if(x < X-1)
                paintFill(x+1, y, color, curColor);
            if(y > 0)
                paintFill(x, y-1, color, curColor);
            if(y < Y-1)
                paintFill(x, y+1, color, curColor);
        }
    }

    public static void checkScreen(){
        for(int i = 0 ; i < Y ; i++){
            for(int j = 0 ; j < X ; j++){
                System.out.printf("[ %s ]", screen[i][j]);
            }
            System.out.println();
        }
        System.out.println();
    }
    public static void main(String args[]){
        String color = "blue";
        screen = new String[Y][X];
        for(int i = 0 ; i < Y ; i++){
            for(int j = 0 ; j < X ; j++){
                if( i%3 == 0 )
                    screen[i][j] = "white";
                else
                    screen[i][j] = "black";
            }
        }
        checkScreen();
        Random rand = new Random();
        int newX = rand.nextInt(X);
        int newY = rand.nextInt(Y);
        paintFill(newX, newY, color, screen[newY][newX]);
    }
}
```
</details>