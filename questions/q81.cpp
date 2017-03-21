/*************************************************************************
	> File Name: q81.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  3/21 20:06:00 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        //类似于二分查找
        int left = 0;
        int right = nums.size() - 1;
        int mid;

        while(left <= right)
        {
            mid = (right + left) >> 1;
            if(nums[mid] == target)
                return true;

            if(nums[right] == nums[mid] && nums[left] == nums[mid])
            {
                right--;
                left++;
            }
            else if(nums[left] <= nums[mid])
            {
                if(nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
            {
                if(nums[mid] < target && nums[right] >= target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}

