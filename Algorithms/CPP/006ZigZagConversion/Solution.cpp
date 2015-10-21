#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows) {
        if(numRows == 1) {
            return s;
        }
        string result = "";
        int interval = 2*numRows-2;
        for(int i=0; i < numRows; i++) {
            int j = i;
            while( j < s.length() ) {
                result += s[j];
                j += (interval - 2*i);
                if( j >= s.length() ) {
                    break;
                }
                if( i!=0 && i != numRows-1 ) {
                    result += s[j];
                }
                j += (2*i);
            }
        }
        return result;
    }
};

int main(int argc, char** argv) {
    string str;
    int n;
    cin >> str >> n;
    Solution mySolution;
    string result = mySolution.convert(str, n);
    cout << result << endl;
    return 0;
}
