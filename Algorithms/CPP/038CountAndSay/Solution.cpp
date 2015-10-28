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
    string countAndSay(int n) {
        string cur = "1";
        string pre = cur;
        for(int i = 2; i <= n; i++) {
            cur = generateStr(pre);
            pre = cur;
        }
        return cur;
    }
    string generateStr(string s) {
        string t = "";

        int cnt = 1;
        for(int i = 0; i+1 < s.length(); i++) {
            if(s[i] == s[i+1]) {
                cnt++;
            } else {
                stringstream ss;
                ss << cnt;
                t += ss.str();
                t += s[i];
                cnt = 1;
            }
        }

        stringstream ss;
        ss << cnt;
        t += ss.str();
        t += s[s.length()-1];

        return t;
    }
};

int main(int argc, char** argv) {
    int n;
    cin >> n;

    Solution* solution = new Solution();
    cout << solution->countAndSay(n) << endl;
    delete solution;

    return 0;
}