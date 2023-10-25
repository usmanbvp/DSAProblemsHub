import java.util.*;
public class Game {
    public Board board;
    Queue<Player> players = new LinkedList<>();
    Queue<Player> winners = new LinkedList<>();
    
    public Game(Board board, Queue<Player> players) {
        this.board = board;
        this.players = players;
    }
    int ranking_position = 0;
    public void launch_game() {
        while(winners.size() < players.size()) {
            Player current_player = players.poll();
            if(current_player.getPosition() == 100){
                continue;
            }
            System.out.println("Roll the dice.");
            Dice dice = new Dice();
            int dice_value = dice.rollDice();
            board.move(current_player,dice_value);
            if(current_player.getPosition() == board.winposition) {
                System.out.printf("%s is the %d st winner of the game.%n",current_player.getUsername(),current_player.getPosition());
                winners.add(current_player);
                ranking_position++;
            }
            else {
                System.out.printf("%s current position : %d%n",current_player.getUsername(),current_player.getPosition());
                players.add(current_player);
            }
        }
    } 
}