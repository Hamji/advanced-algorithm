## 8.8

> 오셀로 게임 규칙은 이러하다. 각각의 오셀로 말은 한쪽 면은 흰색으로,  
> 다른 한쪽 면은 검정색으로 칠해져 있다. 상대편 말에 왼쪽과 오른쪽, 또는  
> 위 아래가 포위된 말은 색상을 뒤집어 상대편 말이 된 것으로 표시한다.  
> 여러분 차례가 오면 여러분은 적어도 하나의 상대편 말을 획득해야 한다.  
> 더 이상 가능한 수가 없는 상태에 도달하면 게임은 종료된다. 승자는  
> 가장 많은 말을 획든한 사람이다. 이 게임을 객체지향적으로 설계 해보라.



김경찬
<details>
<summary>접기/펼치기 버튼</summary>

``` java
  
public enum Color{
    White, Black
}
// 한 게임
public class Game{
    private Piece[][] Board;
    private Player[2] players
    private Color turn;
    private int row;
    private int col;
    public Game(int row, int col, Player player1, Player player2, Color turn){
        this.row = row;
        this.col = col;
        this.players[Color.White] = player1;
        this.players[Color.Black] = player2;
        this.turn = turn;
        this.Board = new Piece[row][col];
    }
    public Player getPlayer1(){
        return this.player1;
    }
    public Player getPlayer2(){
        return this.player2;
    }
    public Color getTurn(){
        return this.turn;
    }
    public Piece[][] getBoard(){
        return this.Board;
    }

    public init(){
        /* 가운데에 흰색, 검은색 말을 두개씩 둔다 */
    }

    public Boolean place(int row, int col){
        /* 말을 둘 수 있으면 지금 차례 색상의 말을 두고 없으면 false 반환 */
        /* 두고나서는 turn을 변경 */
        this.Board[row][col] = new Piece(row,col,turn);
    }
    public Boolean checkReverse(){
        /* 둘러 쌓인 말이 있다면 감지하여 뒤집어준다 */
        /* 없다면 게임을 종료한다 */
    }
    public int reversePieces(Piece start, Piece end){
        /* 시작점부터 끝점까지의 말을 뒤집어준다 */
        /* 뒤집힌 말의 개수를 반환하여 점수화한다 */
    }
    public void changeScore(Player player, int value){
        /* value만큼의 점수를 player에 더해준다 */
        player.setScore(player.getColor() + value);
    }
}
// 유저
public class Player{
    private String name;
    private int score;
    public Player(String name){
        this.setName = name;
        this.score = 0;
    }
    public String getName(){
        return this.name
    }
    public void setName(String name){
        this.name = name;
    }
    public int getScore(){
        return this.score
    }
    public void setScore(int score){
        this.score = score;
    }

    public doPlace(int row, int col, Game game){
        /* Game객체의 board에 말을 둠 */
        game.place(row, col)
    }
}

public class Piece{
    private Color color;
    private int row;
    private int col;
    public Piece(int row, int col, Color color){
        this.color = color;
        this.row = row;
        this.col = col;
    }
    public Color getColor(){
        return this.color;
    }
    public Color getRow(){
        return this.row;
    }
    public Color getCol(){
        return this.col;
    }

    public void reverse(){
        /* 말을 뒤집음 */
        if(this.color == Color.Black)
            this.color = Color.White
        else
            this.color = color.Black
    }
}
  
```
  

</details>
