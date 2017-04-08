/*************************************************************************
	> File Name: q36.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  4/ 8 20:07:00 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {

        vector<short> col(9, 0);
        vector<short> block(9, 0);
        vector<short> row(9, 0);
        
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int idx = 1 << (board[i][j] - '0');
                    if (row[i] & idx || col[j] & idx || block[i/3 * 3 + j / 3] & idx)
                        return false;
                    row[i] |= idx;
                    col[j] |= idx;
                    block[i/3 * 3 + j/3] |= idx;
                }
            }

        return true;
    }
};

int main()
{
    return 0;
}
