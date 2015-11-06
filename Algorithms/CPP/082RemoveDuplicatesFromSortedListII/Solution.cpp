#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    static void createList(ListNode* head) {
        ListNode* p = head;
        int input;
        cin >> input;
        while(input != -1) {
            ListNode* q = new ListNode(input);
            p->next = q;
            p = p->next;
            cin >> input;
        }
    }

    static void printList(ListNode* head) {
        ListNode* p = head;
        while(p!=NULL) {
            cout << p->val << ' ';
            p = p->next;
        }
        cout << endl;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) {
            return head;
        }
        ListNode* result = new ListNode(0);
        result->next = head;

        ListNode* pre = result;
        ListNode* cur = head;
        ListNode* nxt = cur->next;

        while(nxt) {
            if(cur->val != nxt->val) {
                pre = cur;
                cur = nxt;
                nxt = cur->next;
            } else {
                int pivot = cur->val;
                while(cur != NULL && nxt != NULL && cur->val == pivot) {
                    pre->next = cur->next;
                    cur = nxt;
                    nxt = nxt->next;
                }
                if(cur->val == pivot) {
                    pre->next = cur->next;
                    cur = nxt;
                }
            }
        }

        return result->next;
    }
};

void createList(ListNode* head);
void printList(ListNode* head);

int main() {
    ListNode* head = new ListNode(0);
    Solution::createList(head);
    head = head->next;

    Solution::printList(head);

    Solution* solution = new Solution();

    ListNode* result = solution->deleteDuplicates(head);

    Solution::printList(result);

    delete solution;

    return 0;
}