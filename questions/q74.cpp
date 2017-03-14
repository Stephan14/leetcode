/*************************************************************************
	> File Name: q74.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  3/14 11:05:39 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        
        if(matrix.empty() || matrix[0].empty())
            return false;

        int row = 0;
        int col = matrix[0].size()-1;
       //利用数据特性从右上角开始遍历 
        while(row < matrix.size() && col >= 0)
        {
            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col] > target)
            {
                col--;   
            }
            else if(matrix[row][col] < target)
            {
                row++;
            }
        }

        return false;
    }
};

int main()
{
    return 0;
}
