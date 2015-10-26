#include<stdio.h>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    Solution() {
    }
    ~Solution() {
    }
    bool isValid(string s) {
        if(s.length() <= 1) {
            return false;
        }

        stack<char> t;
        int i = 0;
        while( i < s.length() ) {
            if(t.empty()) {
                t.push(s[i]);
            } else {
                if( (t.top()=='{' && s[i]=='}') || (t.top()=='[' && s[i]==']') || (t.top()=='(' && s[i]==')') ) {
                    t.pop();
                } else {
                    t.push(s[i]);
                }
            }
            i++;
        }
        if( t.empty() ) {
            return true;
        } else {
            return false;
        }
    }
};

int main(int argc, char** argv) {
    string str;
    cin >> str;
    Solution* solution = new Solution();
    cout << solution->isValid(str) << endl;
    return 0;
}