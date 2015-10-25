/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) {
            return head;
        }
        int len = 1;
        ListNode* p = head;
        while(p->next!=NULL) {
            len++;
            p = p->next;
        }
        
        int pos = len+1-n;
        p = head;
        ListNode* pre=p;
        ListNode* cur=p;
        while(p->next && --pos) {
            pre = p;
            cur = p->next;
            p = p->next;
        }
        if(pre == cur) {
            head = head->next;
        } else {
            pre->next = cur->next;
        }
        return head;
    }
};