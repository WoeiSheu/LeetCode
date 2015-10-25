#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    Solution() {
    }
    ~Solution() {
    }
    string longestCommonPrefix(vector<string>& strs) {
        if( strs.empty() ) {
            return "";
        }
        string longest = strs.back();
        strs.pop_back();
        while( !strs.empty() ) {
            string current = strs.back();
            int len = ( longest.length() > current.length() ? current.length() : longest.length() );
            int position = 0;
            for( ; position < len; position++) {
                if( longest[position] != current[position] ) {
                    break;
                }
            }
            longest = longest.substr(0,position);
            if(longest == "") {
                break;
            }
            strs.pop_back();
        }
        return longest;
    }
};

int main(int argc, char** argv) {
    vector<string> strs;
    string str;
    cin >> str;
    while( str != "end" ) {
        strs.push_back(str);
        cin >> str;
    }
    Solution* solution = new Solution();
    cout << solution->longestCommonPrefix(strs) << endl;
    return 0;
}