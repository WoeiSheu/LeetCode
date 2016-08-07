#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string output = "";

        int digits[4];
        int divisor = 1000;

        for(int i = 0; i < 4; i++) {
            digits[i] = num / divisor;
            num = num % divisor;
            divisor /= 10;
        }

        for(int i = 3; i >= 0; i--) {
            string append = "";
            switch(i) {
                case 3:
                    if(digits[i] < 4) {
                        for(int j = 0; j < digits[i]; j++) {
                            append += "I";
                        }
                    } else if(digits[i] == 4) {
                        append = "IV";
                    } else if(digits[i] == 5) {
                        append = "V";
                    } else if(digits[i] < 9) {
                        append = "V";
                        for(int j = 0; j < digits[i] - 5; j++) {
                            append += "I";
                        }
                    } else if(digits[i] == 9) {
                        append = "IX";
                    }
                    break;
                case 2:
                    if(digits[i] < 4) {
                        for(int j = 0; j < digits[i]; j++) {
                            append += "X";
                        }
                    } else if(digits[i] == 4) {
                        append = "XL";
                    } else if(digits[i] == 5) {
                        append = "L";
                    } else if(digits[i] < 9) {
                        append = "L";
                        for(int j = 0; j < digits[i] - 5; j++) {
                            append += "X";
                        }
                    } else if(digits[i] == 9) {
                        append = "XC";
                    }
                    break;
                case 1:
                    if(digits[i] < 4) {
                        for(int j = 0; j < digits[i]; j++) {
                            append += "C";
                        }
                    } else if(digits[i] == 4) {
                        append = "CD";
                    } else if(digits[i] == 5) {
                        append = "D";
                    } else if(digits[i] < 9) {
                        append = "D";
                        for(int j = 0; j < digits[i] - 5; j++) {
                            append += "C";
                        }
                    } else if(digits[i] == 9) {
                        append = "CM";
                    }
                    break;
                case 0:
                    for(int j = 0; j < digits[i]; j++) {
                        append += "M";
                    }
                    break;
                default:
                    break;
            }
            output = append + output;
        }

        return output;
    }
};

int main(int argc, char** argv) {
    int num;
    cin >> num;
    Solution* solution = new Solution();
    string roman = solution->intToRoman(num);
    cout << num << ": " << roman << endl;
}
