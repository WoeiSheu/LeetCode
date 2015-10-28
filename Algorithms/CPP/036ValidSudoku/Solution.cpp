#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {};
    ~Solution() {};

    bool isValidSudoku(vector<vector<char>>& board) {
        int dimension = board.size();

        vector<vector<bool>> row, column, block;
        for (int i = 0; i < dimension; i++) {
            vector<bool> temp;
            for (int j = 0; j < dimension; j++) {
                temp.push_back(false);
            }
            row.push_back(temp);
            column.push_back(temp);
            block.push_back(temp);
        }

        for (int i = 0; i < dimension; i++) {
            for (int j = 0; j < dimension; j++) {
                int cur = board[i][j] - '0' - 1;
                if (cur != '.' - '0' - 1) {
                    if (!row[i][cur]) {
                        row[i][cur] = true;
                    } else {
                        return false;
                    }
                    if (!column[j][cur]) {
                        column[j][cur] = true;
                    } else {
                        return false;
                    }
                    int index = (i / 3)*(dimension / 3)+(j / 3);
                    if (!block[index][cur]) {
                        block[index][cur] = true;
                    } else {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

int main(int argc, char** argv) {
    vector<vector<char>> board;
    string s;

    cin >> s;
    for (int i = 0; s != "0"; i++) {
        vector<char> temp;
        for (int j = 0; j < s.length(); j++) {
            temp.push_back(s[j]);
        }
        board.push_back(temp);
        cin >> s;
    }

    Solution* solution = new Solution();
    cout << solution->isValidSudoku(board) << endl;
    delete solution;

    system("pause");
    return 0;
}