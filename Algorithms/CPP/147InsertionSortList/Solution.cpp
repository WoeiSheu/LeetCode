#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* result = new ListNode(0);
        result->next = head;
        head = head->next;
        result->next->next = NULL;

        while(head!=NULL) {
            ListNode* p = result->next;
            ListNode* pre = result;
            while(p!=NULL) {
                if(p->val <= head->val) {
                    pre = p;
                    p = p->next;
                } else {
                    ListNode* q = head;
                    head = head->next;
                    pre->next = q;
                    q->next = p;
                    break;
                }
            }
            if(p==NULL) {
                ListNode* q = head;
                head = head->next;
                pre->next = q;
                q->next = p;
            }
        }
        return result->next;
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
    ListNode* result = solution->insertionSortList(head);

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