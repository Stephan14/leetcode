/*************************************************************************
	> File Name: q41.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  2/27 20:49:17 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    //类似于计数排序
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0 && nums[i] <= nums.size())
            {
                swap(nums[i], nums[nums[i] - 1]);
            } 
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != i + 1)
                return i + 1;
        }

        return nums.size() + 1;
    }
};

