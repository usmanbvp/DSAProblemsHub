
import java.util.Scanner;

public class Keypad {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = scanner.nextInt();

        String[] result = keypadSol(n);
        for (String s : result) {
            System.out.println(s);
        }
        scanner.close();
    }

    public static String[] keypadSol(int n) {
        if (n == 0 || n == 1) {
            String ans[] = { "" };
            return ans;
        }
        int newN = n % 10;
        String[] ans = keypadSol(n / 10);
        String helpans = helper(newN);
        String finalans[] = new String[helpans.length() * ans.length];
        int k = 0;
        for (int i = 0; i < ans.length; i++) {
            for (int j = 0; j < helpans.length(); j++) {
                finalans[k] = ans[i] + helpans.charAt(j);
                k++;
            }
        }
        return finalans;
    }

    private static String helper(int newN) {
        if (newN == 2)
            return "abc";
        if (newN == 3)
            return "def";
        if (newN == 4)
            return "ghi";
        if (newN == 5)
            return "jkl";
        if (newN == 6)
            return "mno";
        if (newN == 7)
            return "pqrs";
        if (newN == 8)
            return "tuv";
        if (newN == 9)
            return "wxyz";
        else
            return "";
    }
}

