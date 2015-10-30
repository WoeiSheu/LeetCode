#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    Solution() {
    }
    ~Solution() {
    }
    int lengthOfLastWord(string s) {
        int pre = 0;
        int cur = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != ' ') {
                cur++;
            } else {
                pre = (cur == 0 ? pre : cur);
                cur = 0;
            }
        }
        if(cur == 0) {
            cur = pre;
        }
        return cur;
    }
};

int main(int argc, char** argv) {
    string s;
    getline(cin,s);

    Solution* solution = new Solution();
    cout << solution->lengthOfLastWord(s) << endl;
    delete solution;

    return 0;
}