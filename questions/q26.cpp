/*************************************************************************
	> File Name: q26.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  2/15 14:55:11 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if(nums.empty())
            return 0;

        int valid = 0;
        for(int index = 1; index < nums.size(); index++)
        {
            if(nums[index] != nums[valid]) 
            {
                nums[++valid] = nums[index];
            }
        }
        
        //删除数组剩余部分
        nums.erase(nums.begin()+valid+1, nums.begin()+nums.size());

        return nums.size();
    }
};

int main()
{
    return 0;
}
