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

    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL) {
            return head;
        }
        ListNode* small = new ListNode(0);
        ListNode* big = new ListNode(0);
        ListNode* p = small;
        ListNode* q = big;
        ListNode* cur = head;

        while(cur) {
            if(cur->val < x) {
                p->next = cur;
                p = p->next;
            } else {
                q->next = cur;
                q = q->next;
            }
            cur = cur->next;
        }
        p->next = NULL;
        q->next = NULL;
        big = big->next;

        p = small;
        ListNode* pre = p;
        while(p){
            pre = p;
            p = p->next;
        }
        pre->next = big;

        return small->next;
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

    int x;
    cin >> x;
    ListNode* result = solution->partition(head,x);

    Solution::printList(result);

    delete solution;

    return 0;
}