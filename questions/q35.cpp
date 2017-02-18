/*************************************************************************
	> File Name: q35.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  2/18 10:08:35 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty())
        return 0;

        int start = 0;
        int end = nums.size() - 1;
        while(start < end)
        {
            int mid = (start + end) >> 1;
            if(nums[mid] < target)
                start = mid + 1;
            else if(nums[mid] > target)
                end = mid - 1;
            else if(nums[mid] == target)
                return mid;
        }
        
        cout << "start: " << start << endl;

        if(nums[start] < target)
            return start + 1; 
        else
            return start;
    }
};

int main()
{
    vector<int> v(1);
    Solution s;
    cout << s.searchInsert(v, 0);
    return 0;
}
