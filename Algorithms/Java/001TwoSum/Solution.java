/**
 * @author Hypocrisy
 * Created by Hypocrisy(虚伪) on 5/19/2015.
 */
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String inputString = scanner.nextLine();
        String[] splitString = inputString.split(" ");
        int len = splitString.length;
        int[] nums = new int[100];
        for(int iCount = 0; iCount < len; iCount++) {
            nums[iCount] = Integer.parseInt(splitString[iCount]);
        }
        int target = Integer.parseInt(scanner.nextLine());

        Solution solution = new Solution();
        int index[] = solution.twoSum(nums, target);

        System.out.println("index1=" + index[0] + ", index2=" + index[1]);
    }

    public int[] twoSum(int[] nums, int target) {
        int[] index = new int[2];
        HashMap<Integer,Integer> hashNums = new HashMap<Integer, Integer>();
        int len = nums.length;
        for(int iCount = 0; iCount < len; iCount++) {
            if(hashNums.containsKey(nums[iCount])) {
                if(nums[iCount]*2 == target) {
                    index[0] = hashNums.get(nums[iCount]) + 1;
                    index[1] = iCount + 1;
                    return index;
                }
            } else {
                hashNums.put(nums[iCount], iCount);
            }
        }

        Set<java.util.Map.Entry<Integer,Integer>> numsSet = hashNums.entrySet();
        Iterator<Map.Entry<Integer,Integer>> numsIterator = numsSet.iterator();

        while(numsIterator.hasNext()) {
            Map.Entry<Integer,Integer> numsEntry = numsIterator.next();
            if(hashNums.containsKey(numsEntry.getKey()) && hashNums.containsKey(target - numsEntry.getKey())) {
                int[] temp = new int[2];
                temp[0] = hashNums.get(numsEntry.getKey()) + 1;
                temp[1] = hashNums.get(target - numsEntry.getKey()) + 1;
                if(temp[0] > temp[1]) {
                    index[0] = temp[1];
                    index[1] = temp[0];
                } else {
                    index[0] = temp[0];
                    index[1] = temp[1];
                }
            }
        }

        return index;
    }
}
