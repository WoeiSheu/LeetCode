#include iostream
#include stdlib.h
#include time.h

using namespace std;

struct ListNode {
     int val;
     ListNode next;
     ListNode(int x)  val(x), next(NULL) {}
 };

class Solution {
public
    static void createList(ListNode head) {
        ListNode p = head;
        int input;
        cin  input;
        while(input != -1) {
            ListNode q = new ListNode(input);
            p-next = q;
            p = p-next;
            cin  input;
        }
    }

    static void printList(ListNode head) {
        ListNode p = head;
        while(p!=NULL) {
            cout  p-val  ' ';
            p = p-next;
        }
        cout  endl;
    }

    ListNode rotateRight(ListNode head, int k) {
        if(head==NULL  k==0) {
            return head;
        }

        ListNode p = head, rear;
        int len = 0;
        while(p!=NULL) {
            len++;
            rear = p;
            p = p-next;
        }

        k = k % len;
        int m = len-k;
        if(k == 0) {
            return head;
        }

        p = head;
        while(--m) {
            p = p-next;
        }
        ListNode result = p-next;
        p-next = NULL;
        rear-next = head;

        return result;
    }
};

void createList(ListNode head);
void printList(ListNode head);

int main() {
    ListNode head = new ListNode(0);
    SolutioncreateList(head);
    head = head-next;

    SolutionprintList(head);

    Solution solution = new Solution();

    int k;
    cin  k;
    ListNode result = solution-rotateRight(head, k);

    SolutionprintList(result);

    delete solution;

    return 0;
}