/*************************************************************************
	> File Name: q34.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  2/17 10:30:29 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        if(nums.empty())
            return result;

        int start = 0;
        int end = nums.size() - 1;
        //将最后的结果向右侧靠
        while(start < end)
        {
            int mid = (start + end) >> 1;
            if(nums[mid] < target) 
                start = mid + 1;
            //将nums[mid] > target 和 nums[mid] = target 合并到一起否则代码如下：
            //else if(nums[mid] > target)
            //   end = mid - 1;
            //else 
            //   end = mid;
            else
                end = mid;
        }

        if(nums[start] != target)
            return result;
        else 
            result[0] = start;

        end = nums.size() - 1;
        //将最后的结果向左侧靠
        while(start < end)
        {
            int mid = ((start + end) >> 1) + 1;
            if(nums[mid] > target)
                end = mid - 1;
            else 
                start = mid;
        }

        result[1] = end;
        return result;
            
    }
};



int main()
{
    return 0;
}
