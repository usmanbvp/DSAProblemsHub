import java.util.Random;

public class Dice {
    public int rollDice() {
        Random random = new Random();
        int result = random.nextInt(6) + 1;
        if(result == 6){
            result += random.nextInt(6) + 1;
        }
        if(result == 12){
            result += random.nextInt(6) + 1;
        }
        if(result == 18){
            return 0;
        }
        return result;
    }
}