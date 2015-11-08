#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int originalLen = nums.size();
        if(originalLen == 0) {
            return 0;
        }
        int i = 0,j = 0;

        int counts = 1;
        for(i = 0; i < originalLen-1; i++) {
            if( nums.at(i) == nums.at(i+1) ) {
                counts++;
                continue;
            } else {
                if(counts >= 2) {
                    nums.at(j++) = nums.at(i);
                    nums.at(j++) = nums.at(i);
                } else {
                    nums.at(j++) = nums.at(i);
                }

                counts = 1;
            }
        }

        if(counts >= 2) {
            nums.at(j++) = nums.at(i);
            nums.at(j) = nums.at(i);
        } else {
            nums.at(j) = nums.at(i);
        }

        return j+1;
    }
};

int main() {
    vector<int> nums;
    int input;
    cin >> input;
    while(input != -1) {
        nums.push_back(input);
        cin >> input;
    }

    for(int i = 0; i < nums.size(); i++) {
        cout << nums.at(i) << ' ';
    }
    cout << endl;

    Solution* solution = new Solution();
    int len = solution->removeDuplicates(nums);

    cout << len << endl;
    for(int i = 0; i < len; i++) {
        cout << nums.at(i) << ' ';
    }
    cout << endl;

    delete solution;
    return 0;
}