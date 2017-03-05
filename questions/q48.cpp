/*************************************************************************
	> File Name: q48.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  3/ 5 21:18:21 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        //先以行为单位反转数组，然后以对角线为对称轴交换数组元素
        reverse(matrix.begin(), matrix.end());
        for(int i = 0; i < matrix.size(); i++)
            for(int j = i; j < matrix[0].size(); j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
    }
};


int main()
{
    return 0;
}

