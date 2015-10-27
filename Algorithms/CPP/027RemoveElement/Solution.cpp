#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    Solution() {
    }
    ~Solution() {
    }

    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); ) {
            if( nums[i] == val ) {
                nums.erase(it);
            } else {
                it++;
            }
        }
        return nums.size();
    }

};

int main(int argc, char** argv) {
    vector<int> nums;
    int input;
    cin >> input;
    while(input!=0) {
        nums.push_back(input);
        cin >> input;
    }

    int val;
    cin >> val;

    Solution* solution = new Solution();
    int len = solution->removeElement(nums, val);

    cout << len << endl;
    while(!nums.empty()) {
        cout << nums.back() << ' ';
        nums.pop_back();
    }
    cout << endl;

    delete solution;

    return 0;
}