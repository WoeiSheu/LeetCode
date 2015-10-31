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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while(m > 0 && n > 0) {
            if(nums1.at(m-1) > nums2.at(n-1)) {
                nums1.at(m+n-1) = nums1.at(m-1);
                m--;
            } else {
                nums1.at(m+n-1) = nums2.at(n-1);
                n--;
            }
        }
        while(n > 0) {
            nums1.at(n-1) = nums2.at(n-1);
            n--;
        }
    }
};

int main(int argc, char** argv) {
    int m = 6, n = 5;
    vector<int> nums1(m+n), nums2(n);

    int input;
    for(int i = 0; i < m; i++)  {
        cin >> input;
        nums1.at(i) = input;
    }

    for(int i = 0; i < n; i++)  {
        cin >> input;
        nums2.at(i) = input;
    }

    Solution* solution = new Solution();
    solution->merge(nums1,m,nums2,n);

    for(int i = 0; i < m+n; i++) {
        cout << nums1.at(i) << ' ';
    }
    cout << endl;

    delete solution;
    return 0;
}