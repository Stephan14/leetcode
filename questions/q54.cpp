/*************************************************************************
	> File Name: q54.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  3/ 6 21:17:05 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        int rowBegin = 0;
        int rowEnd = matrix.size() - 1;
        int colBegin = 0;
        int colEnd = matrix[0].size() - 1;
        vector<int> res;

        if (matrix.empty() || matrix[0].empty()) return res;

        while(rowBegin <= rowEnd && colBegin <= colEnd ) 
        {
            for(int i = colBegin; i <= colEnd; i++)
            {
                res.push_back(matrix[rowBegin][i]);
            }
            rowBegin++;
            
            for(int i = rowBegin; i <= rowEnd; i++)
            {
                res.push_back(matrix[i][colEnd]);  
            }
            colEnd--;

            for(int i = colEnd; i >= colBegin; i--)
            {
                res.push_back(matrix[rowEnd][i]);
            }
            rowEnd--;

            for(int i = rowEnd; i >= rowBegin; i--)
            {
                res.push_back(matrix[i][colBegin]);
            }
            colBegin++;
        }
        return res;
    }
};


int main()
{
    return 0;
}
