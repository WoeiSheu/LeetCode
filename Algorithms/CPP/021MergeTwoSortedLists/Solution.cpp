#include<stdio.h>
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l3 = (ListNode*)malloc(sizeof(ListNode));
        l3->next = NULL;
        l3->val = 0;

        ListNode* p = l3;
        while(l1!=NULL && l2!=NULL) {
            ListNode* q = (ListNode*)malloc(sizeof(ListNode));
            if(l1->val < l2->val) {
                q->val = l1->val;
                l1 = l1->next;
            } else {
                q->val = l2->val;
                l2 = l2->next;
            }
            q->next = NULL;
            p->next = q;
            p = q;

        }
        if(l1!=NULL) {
            p->next = l1;
        }
        if(l2!=NULL) {
            p->next = l2;
        }

        l3 = l3->next;
        return l3;
    }
};

int main(int argc, char** argv) {
    ListNode* l1 = (ListNode*)malloc(sizeof(ListNode));
    l1->next = NULL;
    ListNode* l2 = (ListNode*)malloc(sizeof(ListNode));
    l2->next = NULL;

    int val;
    cin >> val;
    l1->val = val;
    ListNode* p = l1;
    while(1) {
        cin >> val;
        if(val==0) {
            break;
        }
        ListNode* q = (ListNode*)malloc(sizeof(ListNode));
        q->val = val;
        q->next = NULL;
        p->next = q;
        p = q;
    }

    cin >> val;
    l2->val = val;
    ListNode* s = l2;
    while(1) {
        cin >> val;
        if(val == 0) {
            break;
        }
        ListNode* q = (ListNode*)malloc(sizeof(ListNode));
        q->val = val;
        q->next = NULL;
        s->next = q;
        s = q;
    }
/*
    while(l1->next!=NULL) {
        cout << l1->val << endl;
        l1 = l1->next;
    }

    while(l2->next!=NULL) {
        cout << l2->val << endl;
        l2 = l2->next;
    }
*/
    ListNode* l3 = (ListNode*)malloc(sizeof(ListNode));
    Solution* solution = new Solution();
    l3 = solution->mergeTwoLists(l1,l2);

    while(l3!=NULL) {
        cout << l3->val << endl;
        l3 = l3->next;
    }

}