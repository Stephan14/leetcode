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
    void solveSudoku(vector<vector<char> > &board) {
        solveSudoku(board, 0, 0);
    }

    bool check(vector<vector<char>> &board, int i, int j, char val)
    {
        int row = i - i%3, column = j - j%3;

        for(int x = 0; x < 9; x++) 
            if(board[x][j] == val) 
                return false;
        for(int y = 0; y < 9; y++) 
            if(board[i][y] == val) 
                return false;
        for(int x = 0; x < 3; x++)
            for(int y = 0; y < 3; y++)
                if(board[row + x][column + y] == val) 
                    return false;
        
        return true;
    }

    bool solveSudoku(vector<vector<char>> &board, int i, int j)
    {
        if(i == 9) 
            return true;
        if(j == 9)
            return solveSudoku(board, i+1, 0);
        if(board[i][j] != '.') 
            return solveSudoku(board, i, j+1);

        for(char c = '1'; c <= '9'; c++)
        {
            if(check(board, i, j, c)) //先检查是否有相同的值，然后修改元素
            {
                board[i][j] = c;
                if(solveSudoku(board, i, j+1)) 
                    return true;
                board[i][j] = '.';
            }
        }

        return false;
    }
};


int main()
{

}
