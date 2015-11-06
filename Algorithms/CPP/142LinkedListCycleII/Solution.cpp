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

    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) {
            return NULL;
        }
        ListNode* p = head;
        ListNode* q = head;
        while(q && q->next)  {
            p = p->next;
            q = q->next->next;
            if(p == q) {
                break;
            }
        }

        ListNode* result;
        if( q==NULL || q->next == NULL) {
            return NULL;
        } else {
            p = head;
            while(p != q) {
                p = p->next;
                q = q->next;
            }
            result = p;
        }

        return result;
    }

    void addCycle(ListNode *head) {
        if(!head) {
            return;
        }
        ListNode* p = head;
        ListNode* pre = head;
        ListNode* q = head->next;
        while(q && q->next) {
            p = p->next;
            pre = q;
            q = q->next->next;
        }
        if(q != NULL) {
            q->next = p;
        } else {
            pre->next = p;
        }
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

    solution->addCycle(head);
    ListNode* result = solution->detectCycle(head);

    if(result!=NULL) {
        cout << result->val << endl;
    } else {
        cout << "No Cycle." << endl;
    }

    delete solution;

    return 0;
}