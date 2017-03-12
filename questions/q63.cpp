/*************************************************************************
	> File Name: q63.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  3/12 11:39:13 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        
        vector<vector<int> > result(obstacleGrid.size(), vector<int>(obstacleGrid.size(), 0));
        if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1) return 0; 

        for(int i = 0; i < obstacleGrid.size(); i++)
            for(int j = 0; j < obstacleGrid[i].size(); j++)   
            {
                if(obstacleGrid[i][j] == 1) 
                    result[i][j] = 0;
                else if(i == 0 && j == 0) 
                    result[i][j] = 1;
                else if(i == 0 && j > 0)
                    result[i][j] = result[i][j-1];
                else if(j == 0 && i < 0)
                    result[i][j] = result[i-1][j];
                else
                    result[i][j] = result[i-1][j] + result[i][j-1]; 
            }
            cout << result.size() << endl;
        return result.back().back();
    }
};
int main()
{
    vector< vector<int> >  a(1, vector<int>(1, 0));
    Solution s;
    cout << s.uniquePathsWithObstacles(a);
    return 0;
}
