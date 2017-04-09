/*************************************************************************
	> File Name: q37.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  4/ 9 08:49:41 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char> >& board) {
       solveSudoku(board, 0, 0); 
    }

    bool solveSudoku(vector<vector<char> > &board, int row, int column)
    {
        for(int indexRow = row; indexRow < board.size(); indexRow++)
            for(int indexColumn = column; indexColumn < board[indexRow].size(); indexColumn++)
            {
                if(board[indexRow][indexColumn] == '.')
                {
                    for(int num = 1; num < 10; num++)
                    {
                        board[indexRow][indexColumn] = num + '0';
                        if(isValid(board, indexRow, indexColumn))
                            if(solveSudoku(board, indexRow, indexColumn + 1))
                                return true;
                        board[indexRow][indexColumn] = '.';
                    }
                }
            }

        return false;
    }

    bool isValid(vector<vector<char> > &board, int row, int column)
    {
        for(int indexRow = 0; indexRow < board.size(); indexRow++)
            if(indexRow != row && board[indexRow][column] == board[row][column])
                return false;

        for(int indexColumn = 0; indexColumn < board[row].size(); indexColumn++)
            if(indexColumn != column && board[row][indexColumn] == board[row][column])
                return false;

        for(int indexRow = 3 * row / 3; indexRow < 3 * row / 3 + 3; indexRow++)
            for(int indexColumn = 3 * column / 3; indexColumn < 3 * column / 3 + 3; indexColumn++)
            {
                if((row != indexRow || column != indexColumn) && board[row][column] == board[indexRow][indexColumn]) 
                    return false;
            }

        return true;
    }
};


int main()
{

}
