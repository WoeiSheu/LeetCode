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

    bool hasCycle(ListNode *head) {
        ListNode* p = head;
        ListNode* q = head;

        while(q && q->next) {
            p = p->next;
            q = q->next->next;
            if(p == q) {
                return true;
            }
        }
        return false;
    }

    void addCycle(ListNode *head) {
        if(!head) {
            return;
        }
        ListNode* p = head;
        ListNode* q = head->next;

        while(q && q->next) {
            p = p->next;
            q = q->next->next;
        }
        q->next = p;
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
    bool result = solution->hasCycle(head);

    cout << result << endl;

    delete solution;

    return 0;
}