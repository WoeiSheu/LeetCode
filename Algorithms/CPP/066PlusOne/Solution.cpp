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
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;

        int carry = 1;
        while(!digits.empty()) {
            int val = (digits.back() + carry) % 10;
            carry = (digits.back() + carry) / 10;
            result.push_back(val);
            digits.pop_back();
        }
        if(carry != 0) {
            result.push_back(carry);
        }

        inverse(result);

        return result;
    }
    void inverse(vector<int>& result) {
        int len = result.size();
        for(int i = 0; i < len/2; i++) {
            result[i] = result[i] ^ result[len-i-1];
            result[len-i-1] = result[i] ^ result[len-i-1];
            result[i] = result[i] ^ result[len-i-1];
        }
    }
};

int main(int argc, char** argv) {
    vector<int> digits;

    int val;
    cin >> val;
    while(val != 10) {
        digits.push_back(val);
        cin >> val;
    }
    Solution* solution = new Solution();
    vector<int> result = solution->plusOne(digits);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    cout << endl;
    delete solution;

    return 0;
}