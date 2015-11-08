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
    int removeDuplicates(vector<int>& nums) {
        int i = 0;

        vector<int>::iterator it = nums.begin();
        while(it!=nums.end() && i < nums.size()-1) {
            if(nums.at(i) == nums.at(i+1)) {
                nums.erase(it);
            } else {
                i++;
                it++;
            }
        }
        int len = nums.size();
        return len;
    }
    // Another better method.
    /*
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) {
            return 0;
        }
        
        int count = 0;
        int i = 0;
        for(i = 0; i < len-1; i++) {
            if(nums.at(i) == nums.at(i+1)) {
                continue;
            } else {
                nums.at(count) = nums.at(i);
                count++;
            }
        }
        nums.at(count) = nums.at(i);
        
        return count+1;
    }
    */
};

int main(int argc, char** argv) {
    vector<int> nums;
    int input;
    cin >> input;
    while(input!=0) {
        nums.push_back(input);
        cin >> input;
    }

    Solution* solution = new Solution();
    int len = solution->removeDuplicates(nums);

    cout << len << endl;
    while(!nums.empty()) {
        cout << nums.back() << ' ';
        nums.pop_back();
    }
    cout << endl;

    delete solution;

    return 0;
}