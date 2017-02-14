/*************************************************************************
	> File Name: q16.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  2/ 9 10:06:46 2017
 ************************************************************************/

#include<vector>
#include<cmath>
#include<iostream>
using namespace std;

class Solution {
    public:
    int threeSumClosest(vector<int>& nums, int target) {
        vector< vector<int> > sum( nums.size(), vector<int>(nums.size(),0) );

        int abs_number = INT_MAX;
        int result = 0;

        if(nums.size() < 3)
            return 0;

        for(int i = 0; i < sum.size(); i++)
            for(int j = i+1; j < sum.size(); j++)
        {
            sum[i][j] = nums[i] + nums[j];
        }

        for(int index = 0; index < nums.size(); index++)
        {
            for(int j = 0; j < nums.size()-1; j++)
            {
                if(index != j)
                {
                    for(int i = j + 1; i < nums.size(); i++)
                    {
                        if(i > index && abs(sum[j][i] + nums[index] - target) < abs_number)
                        {
                            abs_number = abs(sum[j][i] + nums[index] - target);
                            result =  sum[j][i] + nums[index];
                        }
                    }
                }
            }
        }
        return result;
    }
};
int main()
{
    vector<int> v(3,0);
    Solution s;
    cout << s.threeSumClosest(v, 1);
    return 0;
}
