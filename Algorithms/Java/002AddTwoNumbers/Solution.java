/**
 * @author Hypocrisy(虚伪)
 * Created by Hypocirsy on 5/23/2015.
 */

public class Solution {

    static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) {
            val = x;
        }
    }

    public static void main(String[] args) {
        ListNode listNode1 = new ListNode(3);
        ListNode listNode2 = new ListNode(7);
        ListNode listNode3 = new ListNode(3);
        ListNode listNode4 = new ListNode(9);
        ListNode listNode5 = new ListNode(2);
        ListNode listNode6 = new ListNode(4);

        listNode3.next = null;
        listNode2.next = listNode3;
        listNode1.next = listNode2;

        listNode6.next = null;
        listNode5.next = listNode6;
        listNode4.next = listNode5;

        ListNode l1 = listNode1;
        ListNode l2 = listNode4;

        Solution solution = new Solution();
        ListNode result = solution.addTwoNumbers(l1,l2);

        while( result.next!=null ) {
            System.out.print(result.val + " -> ");
            result = result.next;
        }

        System.out.print(result.val);
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        ListNode listNode = new ListNode((l1.val + l2.val + carry) % 10);   //头节点

        //l1和l2都只有1位需要提前判断
        if(l1.val + l2.val >= 10) {
            carry = 1;
        }

        ListNode headNode = listNode;   //头节点
        ListNode nextListNode;

        while(l1.next != null && l2.next != null) { //l1和l2都未到达链表结尾
            l1 = l1.next;
            l2 = l2.next;

            nextListNode = new ListNode((l1.val + l2.val + carry) % 10);
            listNode.next = nextListNode;
            listNode = nextListNode;

            if((l1.val + l2.val + carry)>= 10) {
                carry = 1;
            } else {
                carry = 0;
            }
        }
        while (l1.next != null) {   //l2已经到结尾,l1没到
            l1 = l1.next;
            nextListNode = new ListNode((l1.val+carry)%10);
            listNode.next = nextListNode;
            listNode = nextListNode;

            if(l1.val + carry >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }
        }
        while (l2.next != null) {   //l1已经到结尾,l2没到
            l2 = l2.next;
            nextListNode = new ListNode((l2.val+carry)%10);
            listNode.next = nextListNode;
            listNode = nextListNode;

            if(l2.val + carry >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }
        }

        if(carry == 1) {    //如果计算最后还有一位进位
            nextListNode = new ListNode(1);
            listNode.next = nextListNode;
            listNode = nextListNode;
        }
        listNode.next = null;
        return headNode;
    }
    /*
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        ListNode listNode = new ListNode((l1.val + l2.val + carry) % 10);   //末尾节点
        listNode.next = null;
        if(l1.val + l2.val >= 10) {
            carry = 1;
        }

        ListNode preListNode;
        while(l1.next != null && l2.next != null) { //l1和l2都未到达链表结尾
            l1 = l1.next;
            l2 = l2.next;
            preListNode = new ListNode((l1.val + l2.val + carry) % 10);
            preListNode.next = listNode;
            listNode = preListNode;
            if((l1.val + l2.val + carry )>= 10) {
                carry = 1;
            } else {
                carry = 0;
            }
        }

        while (l1.next != null) {   //l2已经到结尾,l1没到
            l1 = l1.next;
            preListNode = new ListNode((l1.val+carry)%10);
            preListNode.next = listNode;
            listNode = preListNode;
            if(l1.val + carry >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }
        }

        while (l2.next != null) {   //l1已经到结尾,l2没到
            l2 = l2.next;
            preListNode = new ListNode((l2.val+carry)%10);
            preListNode.next = listNode;
            listNode = preListNode;
            if(l2.val + carry >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }
        }

        if(carry == 1) {    //如果计算最后还有一位进位
            preListNode = new ListNode(1);
            preListNode.next = listNode;
            listNode = preListNode;
        }
        return listNode;
    }
    */
}