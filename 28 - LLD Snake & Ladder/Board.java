public class Board {

    Ladder ladder = new Ladder();
    Snakes snake = new Snakes();
    
    private int size_of_board;
    public int winposition = 100;

    public Board(int size) {
        this.size_of_board = size * size;
    }

    public void move(Player player,int result){
        if(player.getPosition() + result > size_of_board) {
            return;
        }
        player.setPosition(player.getPosition() + result);

        if(player.getPosition() == snake.getStartPosition()) {
            player.setPosition(snake.getEndPosition());
        }

        if(player.getPosition() == ladder.getStartPosition()) {
            player.setPosition(ladder.getEndPosition());

        }
    }
}