#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* p1 = head;
        ListNode* p2 = head->next;

        while(p2 && p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }

        p2 = p1->next;
        p1->next = NULL;

        return mergeTwoLists( sortList(head), sortList(p2) );
    }
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode* q1 = head1;
        ListNode* q2 = head2;
        static ListNode dummy(0);       //中间过程变量temporary
        dummy.next = q1;

        ListNode* previous = &dummy;
        while(q1 && q2) {
            if(q1->val < q2->val) {
                previous = q1;
                q1 = q1->next;
            } else {
                previous->next = q2;
                q2 = q2->next;
                previous = previous->next;
                previous->next = q1;
            }
        }
        if(q2) {
            previous->next = q2;
        }

        return dummy.next;
    }
};

void createList(ListNode* head);
void printList(ListNode* head);

int main() {
    ListNode* head = new ListNode(0);
    createList(head);
    head = head->next;

    printList(head);

    Solution* solution = new Solution();
    ListNode* result = solution->sortList(head);

    printList(result);

    delete solution;
    delete result;

    return 0;
}

void createList(ListNode* head) {
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

void printList(ListNode* head) {
    ListNode* p = head;
    while(p!=NULL) {
        cout << p->val << ' ';
        p = p->next;
    }
    cout << endl;
}