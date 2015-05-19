/**
 * @author Hypocrisy
 * Created by Hypocrisy(许炜) on 5/19/2015.
 */
import java.util.Scanner;

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
        //List<int> numsList = Arrays.asList(nums);     //这样写会错,因为Arrays.asList的参数是一个对象类型数组,而int是个基本类型,不可用,若是Integer即可
        int len = nums.length;
        for(int iCount = 0; iCount < len-1; iCount++) {
            for(int jCount = iCount+1; jCount < len; jCount++) {
                if(target == nums[iCount]+nums[jCount]) {
                    index[0] = iCount+1;
                    index[1] = jCount+1;
                }
            }
        }
        return index;
    }
}
