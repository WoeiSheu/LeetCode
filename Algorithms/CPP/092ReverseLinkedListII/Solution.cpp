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

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL || head->next==NULL || m==n) {
            return head;
        }
        ListNode* result = new ListNode(0);
        result->next = head;

        ListNode* pre = result;
        ListNode* cur = head;
        ListNode* nxt = cur->next;
        while(--m && --n && nxt) {
        // notice that when n will decrease one time less that m!!!!!!!!!!!!!!!!!!!
            pre = cur;
            cur = nxt;
            nxt = nxt->next;
        }

        ListNode* start = pre;
        ListNode* rear = cur;

        pre = cur;
        cur = nxt;
        if(nxt) {
            nxt = nxt->next;
        }

        while(--n && nxt) {
        // so here we should use --n not n--, and so we can not use (nxt && --n)
            cur->next = pre;
            pre = cur;
            cur = nxt;
            nxt = nxt->next;
        }

        if(n) {
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        start->next = pre;
        rear->next = cur;

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

    int m,n;
    cin >> m >> n;
    ListNode* result = solution->reverseBetween(head,m,n);

    Solution::printList(result);

    delete solution;

    return 0;
}