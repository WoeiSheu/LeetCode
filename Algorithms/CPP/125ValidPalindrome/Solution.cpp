#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0,right = s.length()-1;
        while(left < right) {
            if(!isalnum(s[left])) {
                left++;
                continue;
            } else if(!isalnum(s[right])) {
                right--;
                continue;
            } else {
                if( s[left] != s[right] && s[left]-s[right] != 'A'-'a' && s[left]-s[right] != 'a'-'A' ) {
                    return false;
                }
                left++;
                right--;
            }
        }
        return true;
    }
};

int main() {
    string str;
    getline(cin,str);
    Solution* solution = new Solution();
    cout << solution->isPalindrome(str) << endl;
    delete solution;

    return 0;
}