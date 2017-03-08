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
        if(nums.empty())
            return 1;
        int n = nums.size();
        int maxIdx = 0;
        for (int i = 0; i < n; ++i) {
            if (i > maxIdx || maxIdx >= n - 1) break;
            maxIdx = max(maxIdx, i + nums[i]);
        }
        return maxIdx >= n - 1;    
    }
};

int main()
{
    return 0;
}
