#include <iostream>

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

    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return;
        }
        ListNode* p = head;
        ListNode* q = head->next;

        while(q && q->next) {
            p = p->next;
            q = q->next->next;
        }
        q = p->next;
        p->next = NULL;
        p = head;

        q = reverseList(q);

        insertList(p,q);
    }
    ListNode* reverseList(ListNode* q) {
        if(q==NULL || q->next==NULL) {
            return q;
        }
        ListNode* pre = q;
        ListNode* cur = q->next;
        ListNode* nxt = cur->next;
        pre->next = NULL;
        while(nxt) {
            cur->next = pre;
            pre = cur;
            cur = nxt;
            nxt = cur->next;
        }
        cur->next = pre;

        return cur;
    }
    void insertList(ListNode* p, ListNode* q) {
        ListNode* dummy = p;
        ListNode* p_prev = p;
        ListNode* q_prev = q;
        while(p && q) {
            p = p->next;
            q = q->next;
            p_prev->next = q_prev;
            q_prev->next = p;
            p_prev = p;
            q_prev = q;
        }
        p = dummy;
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
    solution->reorderList(head);

    Solution::printList(head);

    delete solution;

    return 0;
}