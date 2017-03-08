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

        int step = nums[0];
        int index = 0;

        while(index + step < nums.size() - 1)
        {
            index = index + step;
            step = nums[index];
            if(step == 0)
                break;
        }

        if(index + step >= nums.size() - 1)
            return 1;
        else 
            return 0;
    }
};

int main()
{
    return 0;
}
