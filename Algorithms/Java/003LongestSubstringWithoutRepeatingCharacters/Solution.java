import java.util.Scanner;
import java.util.HashMap;
import java.util.Stack;
/**
 * @author Hypocrisy(虚伪)
 * Created by Hypocrisy on 5/23/2015.
 */
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        Solution solution = new Solution();
        int len = solution.lengthOfLongestSubstring(s);
        System.out.println(len);
    }

    public int lengthOfLongestSubstring(String s) {
        int maxLength = 0;
        Stack<Integer> lengthCollection = new Stack<Integer>();

        char[] charArray = s.toCharArray();
        HashMap<Character,Integer> hashMap = new HashMap<Character, Integer>();
        int formerLocation = 0;
        int laterLocation = 0;
        for(int i = 0; i < s.length(); i++) {
            if(!hashMap.containsKey(charArray[i])) {
                hashMap.put(charArray[i],i);
            } else {
                laterLocation = i;
                int length = laterLocation - formerLocation;

                if(formerLocation <= hashMap.get(charArray[i]) + 1) {   //只有在前一个位置比当前状态字符对应位置靠前时,才让前一个位置等于后一个位置
                    formerLocation = hashMap.get(charArray[i]) + 1;
                }
                hashMap.put(charArray[i],i);

                lengthCollection.push(Integer.valueOf(length));
            }
        }
        laterLocation = s.length();
        lengthCollection.push(laterLocation-formerLocation);

        while (!lengthCollection.isEmpty()) {
            int temp = lengthCollection.pop();
            if (maxLength < temp) {
                maxLength = temp;
            }
        }
        return maxLength;
    }
}
