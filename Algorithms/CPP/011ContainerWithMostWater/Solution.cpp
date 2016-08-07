#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxCapability = 0;
        while(left < right) {
            int minHeightOfTwo = 0;
            if( height.at(left) < height.at(right) ) {
                minHeightOfTwo = height.at(left);
                left++;
            } else {
                minHeightOfTwo = height.at(right);
                right--;
            }
            int capability = minHeightOfTwo*(right-left+1);
            if(maxCapability < capability) {
                maxCapability = capability;
            }
        }

        return maxCapability;
    }
};

int main() {
    vector<int> height;
    int input;
    cin >> input;
    while(input!=-1) {
        height.push_back(input);
        cin >> input;
    }

    Solution* solution = new Solution();
    int maxArea = solution->maxArea(height);
    cout << maxArea << endl;

    delete solution;
    return 0;
}