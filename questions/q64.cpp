/*************************************************************************
	> File Name: q64.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  3/13 09:41:34 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
       
        if(grid.empty() || grid[0].empty())
            return 0;

        vector<vector<int> > result(grid.size(), vector<int>(grid[0].size(), 0)); 
       //典型的动态规划 
        for(int i = 0; i < result.size(); i++)
            for(int j = 0; j < result[i].size(); j++)
            {
                if(i == 0 && j == 0)
                    result[i][j] = grid[i][j];
                else if(i == 0) 
                    result[i][j] = result[i][j-1] + grid[i][j];
                else if(j == 0)
                    result[i][j] = result[i-1][j] + grid[i][j];
                else
                    result[i][j] = min(result[i-1][j], result[i][j-1]) + grid[i][j];
            }

        return result.back().back();
    }
};


int main()
{
    return 0;
}
