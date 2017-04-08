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
        
        if(board.empty() || board[0].empty())
            return false;

        int row = board.size();
        int column = board[0].size();

        vector<vector<bool> > rowFlag(row, vector<bool>(column, false));
        vector<vector<bool> > columnFlag(row, vector<bool>(column, false));
        vector<vector<bool> > cellFlag(row, vector<bool>(column, false));

        for(int indexRow = 0; indexRow < row; indexRow++)
            for(int indexColumn = 0; indexColumn < column; indexColumn++)
            {
                if(board[indexRow][indexColumn] > '0' && board[indexRow][indexColumn] <= '9')
                {
                    int num = board[indexRow][indexColumn] - '1';
                    if(rowFlag[indexRow][num] || columnFlag[num][indexColumn] || cellFlag[3 * (indexRow / 3) + indexColumn / 3][num])
                        return false;

                    rowFlag[indexRow][num] = true;
                    columnFlag[num][indexColumn] = true;
                    cellFlag[3 * (indexRow / 3) + indexColumn / 3 ][num] = true;
                }
            }

        return true;
    }
};

int main()
{
    return 0;
}
