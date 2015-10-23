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
    int romanToInt(string s) {
        int integer = 0;

        int s2array[20] = {0};
        for(int i = 0; i < s.length(); i++) {
            switch(s[i]) {
                case 'I': s2array[i] = 1; break;
                case 'V': s2array[i] = 5; break;
                case 'X': s2array[i] = 10; break;
                case 'L': s2array[i] = 50; break;
                case 'C': s2array[i] = 100; break;
                case 'D': s2array[i] = 500; break;
                case 'M': s2array[i] = 1000; break;
                default: cout << "Please input valid roman number." << endl;
            }
        }

        int current = 0, next = 0;
        for(int i = 0; i < s.length(); i++) {
            current = s2array[i];
            if(i < s.length()-1) {
                next = s2array[i+1];
            }
            if(current < next) {
                integer -= current;
            } else {
                integer += current;
            }
        }
        return integer;
    }
};

int main(int argc, char** argv) {
    string str;
    cin >> str;
    Solution* solution = new Solution();
    cout << solution->romanToInt(str) << endl;
    return 0;
}
