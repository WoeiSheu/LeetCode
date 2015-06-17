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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) {
            return head;
        }
        ListNode* p = head;
        ListNode* q = p->next;
        while(q!=NULL) {
            if(q->val == val) {
                p->next = q->next;
            } else {
                p = p->next;
            }
            q = q->next;
        }
        if(head->val == val) {
            head = head->next;
        }
        return head;
    }
};