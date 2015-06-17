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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) {
            return head;
        }
        ListNode* previous = head;
        ListNode* current = previous->next;
        ListNode* next = current->next;
        previous->next = NULL;
        
        while(current->next!=NULL) {
            current->next = previous;
            previous = current;
            current = next;
            next = next->next;
        }
        current->next = previous;
        
        return current;
    }
};