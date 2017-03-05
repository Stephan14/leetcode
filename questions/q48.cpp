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
        //首先以以反对角线为轴翻转，然后再以x轴中线上下翻转即可得到结果
        int n = matrix.size();

        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i; ++j) {
                swap(matrix[i][j], matrix[n - 1- j][n - 1 - i]);
            }
        }

        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - 1 - i][j]);
            }
        }
    }

};


int main()
{
    return 0;
}

