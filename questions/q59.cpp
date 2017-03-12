/*************************************************************************
	> File Name: q59.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  3/12 09:43:49 2017
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
       
        vector< vector<int> > result(n, vector<int>(n, 0));
       
        int p = n, q = n;
        int value = 1;
        
        for(int i = 0; i < n/2; i++, p -= 2, q -= 2)
        {
            for(int j = i; j < i + p; j++) 
            {
                result[i][j] = value++; 
            }

            for(int j = i + 1; j < i + p; j++)
            {
               result[j][i+p-1] = value++; 
            }

            for(int j = i + p - 2; j >= i; j--)
            {
                result[i+p-1][j] = value++;
            }

            for(int j = i + p - 21; j > i; j--)
            {
                result[j][i] = value++;
            }
        }
        if(n % 2 != 0) result[n/2][n/2] = value;
        return result;
    }
};

int main()
{

}

