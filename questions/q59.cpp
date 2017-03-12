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
        int rowBegin = 0;
        int rowEnd = result.size();
        int colBegin = 0;
        int colEnd = result[0].size();
        int value = 1;

        while(rowBegin <= rowEnd && colBegin <= colEnd)
        {
            for(int i = colBegin; i <= colEnd; i++) 
            {
                result[rowBegin][i] = value++;    
            }
            rowBegin++;

            for(int i = rowBegin; i <= rowEnd; i++)
            {
               result[i][colEnd] = value++;
            }
            colEnd--;
            
            if(rowBegin <= rowEnd)
            {
                for(int i = colEnd; i >= colBegin; i--)
                {
                    result[rowEnd][i] = value++;
                }
                rowEnd--;
            }

            if(colBegin <= colEnd)
            {
                for(int i = rowEnd; i >= rowBegin; i-- )
                {
                   result[i][colBegin] = value++;
                }
                colBegin++;
            }
        }
        return result;
    }
};

int main()
{

}

