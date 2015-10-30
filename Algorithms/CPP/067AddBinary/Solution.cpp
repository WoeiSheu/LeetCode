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
    string addBinary(string a, string b) {
        string c = "";

        int carry = 0;
        int i = a.length()-1, j = b.length()-1;
        while(i>=0 && j>=0) {
            int val = (a[i] - '0' + b[j] - '0' + carry) % 2;
            carry = (a[i] - '0' + b[j] - '0' + carry) / 2;
            stringstream ss;
            ss << val;
            c = ss.str() + c;
            i--;
            j--;
        }

        while(i>=0) {
            int val = (a[i] - '0' + carry) % 2;
            carry = (a[i] - '0' + carry) / 2;
            stringstream ss;
            ss << val;
            c = ss.str() + c;
            i--;
        }

        while(j>=0) {
            int val = (b[j] - '0' + carry) % 2;
            carry = (b[j] - '0' + carry) / 2;
            stringstream ss;
            ss << val;
            c = ss.str() + c;
            j--;
        }

        if(carry != 0) {
            c = "1" + c;
        }
        return c;
    }
};

int main(int argc, char** argv) {
    string a,b;
    cin >> a >> b;

    Solution* solution = new Solution();
    string result = solution->addBinary(a,b);
    cout << result << endl;
    delete solution;

    return 0;
}