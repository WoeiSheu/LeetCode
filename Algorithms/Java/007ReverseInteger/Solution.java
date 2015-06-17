/**
 * @author Hypocrisy(虚伪)
 * Created by Hypocrisy on 5/25/2015.
 */
import java.util.InputMismatchException;
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        int x = Integer.parseInt(s);
        Solution solution = new Solution();

        int y = solution.reverse(x);
        System.out.println(y);
    }
    public int reverse(int x) {
        long xReverse = 0;

        int sign = 0;
        if(x < 0) {
            sign = 1;
        }

        int bits = (new Integer(x)).toString().length() - sign;

        while(bits>0) {
            int bit = x%10; //取余数是保持符号的
            xReverse += (bit * (Math.pow(10, bits - 1)));
            x /= 10;
            --bits;
        }

        if(xReverse > Integer.MAX_VALUE || xReverse < Integer.MIN_VALUE) {
            xReverse = 0;
        }
        return (int)xReverse;
    }
}