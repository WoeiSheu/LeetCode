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
    int climbStairs(int n) {
        if(n==0){
            return 0;
        }
        int pre1=1,pre2=1,cur=1;
        for(int i=2; i <= n; i++) {
            cur = pre1+pre2;
            pre2=pre1;
            pre1=cur;
        }
        return cur;
    }
    /* It will exceed the time.
    int climbStairs(int n) {
        if(n==0 || n == 1){
            return 1;
        }
        int ways = climbStairs(n-1) + climbStairs(n-2);
        return ways;
    }
    */
};

int main(int argc, char** argv) {
    int n;
    cin >> n;

    Solution* solution = new Solution();
    int result = solution->climbStairs(n);
    cout << result << endl;
    delete solution;

    return 0;
}