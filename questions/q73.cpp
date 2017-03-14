/*************************************************************************
	> File Name: q73.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  3/14 09:49:26 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        
        if(matrix.empty() || matrix[0].empty())
            return;

        bool rowZero = false;
        bool colZero = false;

        for(int i = 0; i < matrix.size(); i++)
            if(matrix[i][0] == 0) 
                colZero = true;

        for(int i = 0; i < matrix[0].size(); i++)
            if(matrix[0][i] == 0)
                rowZero = true;
        
        //根据数组中只更新第一行、第一列的标记
        for(int i = 1; i < matrix.size(); i++)
            for(int j = 1; j < matrix[j].size(); j++)
            {
                if(matrix[i][j] == 0) 
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }

        //根据第一行、第一列的值更新数组中值
        for(int i = 1; i < matrix.size(); i++)
            for(int j = 1; j < matrix[i].size(); j++)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) 
                    matrix[i][j] = 0;
            }

        if(colZero)
            for(int i = 0; i < matrix.size(); i++)
                matrix[i][0] = 0;

        if(rowZero)
            for(int i = 0; i < matrix[0].size(); i++)
                matrix[0][i] = 0;

    }

    
};

int main()
{
    vector<vector<int> > result;
    
    return 0;
}
