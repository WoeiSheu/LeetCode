#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    Solution() {
    }
    ~Solution() {
    }
    int myAtoi(string str) {
        int const INT_MAX = 2147483647;
        int const INT_MIN = -2147483648;
        long long number = 0;

        int len = str.length();
        int symbol = 0;     //0 represent plus, add 1 represent minus.
        int i = 0;

        while( (str[i] == ' ' || str[i] == '\n' || str[i] == '\r') && i < len) {
            i++;
        }
        if(i == len) {
            return (int)number;
        } else {
            if( str[i] >= '0' && str[i] <= '9' ) {
                symbol = 0;
            } else if( str[i] == '-' ) {
                symbol = 1;
                i++;
            } else if( str[i] == '+' ) {
                symbol = 0;
                i++;
            } else {
                return (int)number;
            }
            if(i == len) {
                return (int)number;
            }
            while(i < len) {
                if( str[i] < '0' || str[i] > '9' ) {
                    i++;
                    break;
                }
                if(symbol == 0) {
                    number = number*10 + (str[i]-'0');
                    if(number > INT_MAX) {
                        number = INT_MAX;
                        return (int)number;
                    }
                } else {
                    number = number*10 - (str[i]-'0');
                    if(number < INT_MIN) {
                        number = INT_MIN;
                        return (int)number;
                    }
                }
                i++;
            }
        }
        return (int)number;
    }
};

int main(int argc, char** argv) {
    string str;
    cin >> str;
    Solution* solution = new Solution();
    int number = solution->myAtoi(str);
    cout << number << endl;
    delete solution;
    return 0;
}