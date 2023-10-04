import java.util.*;

public class Driver {
    public static void main(String [] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<String> lst = new ArrayList<>();
        Board board = new Board(10);
        Queue<Player> queue = new LinkedList<>();
        Player p1 = new Player("User1",0);
        Player p2 = new Player("User2",0);
        queue.add(p1);
        queue.add(p2);
        Game game = new Game(board,queue);
        Ladder l1 = new Ladder();
        l1.ladder_values(51,87);
        Ladder l2 = new Ladder();
        l2.ladder_values(78,98);
        Ladder l3 = new Ladder();
        l3.ladder_values(15,37);
        Snakes s1 = new Snakes();
        s1.snakes_values(16,4);
        Snakes s2 = new Snakes();
        s2.snakes_values(32,14);
        Snakes s3 = new Snakes();
        s3.snakes_values(64,41);
        Snakes s4 = new Snakes();
        s4.snakes_values(94,6);
        game.launch_game();
    }
}
