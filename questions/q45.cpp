/*************************************************************************
	> File Name: q45.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  3/ 3 21:59:55 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
    
        int i = 0;
        int level = 0;
        int nextMax = 0;
        int currentMax = 0;
        //类似于广度优先遍历的思想
        if(nums.size() < 2) return 0;

        while(currentMax - i + 1 > 0)
        {
            level++;
            for(; i <= currentMax; i++)
            {
                nextMax = max(nextMax, nums[i] + i); 
                if(nextMax >= nums.size() - 1)
                    return level;
            }
            currentMax = nextMax;
        }
        
        return 0;
    }
};

int main()
{
    return 0;
}
