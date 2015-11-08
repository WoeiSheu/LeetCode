#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if(len == 0 || len == 1) {
            return s;
        }

        vector<int> lenOfPosition(1000,0);
        int i;
        for(i = 0; i < len-2; i++) {
            int longest = 0;
            if(s[i] == s[i+1]) {
                longest = 2;
                int left = i-1, right = i+2;
                while( (left >= 0) && (right < len) && (s[left--] == s[right++]) ) {
                    longest += 2;
                }
                lenOfPosition.at(i) = longest;
            }

            if (s[i] == s[i+2]) {
                longest = 3;
                int left = i-1, right = i+3;
                while( (left >= 0) && (right < len) && (s[left--] == s[right++]) ) {
                    longest += 2;
                }
                if(lenOfPosition.at(i) < longest) {
                    lenOfPosition.at(i) = longest;
                }
            }

        }

        if(s[i] == s[i+1]) {
            lenOfPosition.at(i) = 2;
        }

        int maxLength = lenOfPosition[0];
        int positionOfMaxLength = 0;
        for(int i = 1; i < len-1; i++) {
            if(lenOfPosition.at(i) > maxLength) {
                maxLength = lenOfPosition.at(i);
                positionOfMaxLength = i+1 - maxLength/2;
            }
        }

        string result = s.substr(positionOfMaxLength, maxLength);
        return result;
    }
};

int main() {
    string s;
    getline(cin,s);

    Solution* solution = new Solution();
    string result = solution->longestPalindrome(s);
    cout << result << endl;

    delete solution;
    return 0;
}

/**
* The dynamic programming solution.
**/


/** 
* The following algorithm is linear time.
* find the explanation here:
* http://articles.leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
**/