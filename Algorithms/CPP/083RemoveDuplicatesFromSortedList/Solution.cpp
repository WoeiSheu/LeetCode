#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    Solution() {
    }
    ~Solution() {
    }
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) {
            return NULL;
        }
        ListNode* result = new ListNode(head->val);

        ListNode* p = result;
        while(head!=NULL) {
            if(head->val != p->val) {
                ListNode* q = new ListNode(head->val);
                p->next = q;
                p = q;
            }
            head = head->next;
        }
        return result;
    }
};

int main(int argc, char** argv) {
    ListNode* head = new ListNode(0);

    ListNode* p = head;
    for(int i = 1; i < 10; i++) {
        ListNode* q = (ListNode*)malloc(sizeof(ListNode));
        q->val = i + i%2;
        q->next = NULL;
        p->next = q;
        p = p->next;
    }

    /*
    while(head->next!=NULL) {
        cout << head->next->val << endl;
        head = head->next;
    }
    */
    Solution* solution = new Solution();
    ListNode* result = solution->deleteDuplicates(head->next);


    while(result!=NULL) {
        cout << result->val << endl;
        result = result->next;
    }


    delete solution;

    return 0;
}