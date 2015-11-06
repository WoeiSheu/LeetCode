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

    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) {
            return head;
        }

        ListNode* result = head->next;

        ListNode* pre = head;
        ListNode* cur = head->next;
        ListNode* nxt = cur->next;

        while(nxt && nxt->next) {
            cur->next = pre;
            pre->next = nxt->next;
            pre = nxt;
            cur = pre->next;
            nxt = cur->next;
        }

        cur->next = pre;
        pre->next = nxt;

        return result;
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

    ListNode* result = solution->swapPairs(head);

    Solution::printList(result);

    delete solution;

    return 0;
}