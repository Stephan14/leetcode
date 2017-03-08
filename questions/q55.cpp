/*************************************************************************
	> File Name: q55.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  3/ 8 09:03:20 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        //动态guihua
        //dp[i]表示走道i位置时剩余的最大步数
        //那么递推公式为：dp[i] = max(dp[i - 1], A[i - 1]) - 1
        if(nums.empty())
            return 1;
        vector<int> dp(nums.size(), 0);

        for(int index = 1; index < nums.size(); index++)
        {
            dp[index] = max(dp[index - 1], nums[index - 1]) - 1;
            if(dp[index] < 0)
                return false;
        }
        return dp[nums.size() - 1] >= 0;
    }
};

int main()
{
    return 0;
}
