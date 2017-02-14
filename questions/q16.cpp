/*************************************************************************
	> File Name: q16.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  2/ 9 10:06:46 2017
 ************************************************************************/

#include<vector>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
    public:
    int threeSumClosest(vector<int>& nums, int target) {

        if(nums.size() < 3)
        return 0;
        sort(nums.begin(), nums.end());

        int result = nums[0] + nums[1] + nums[2];

        for(int index = 0; index < nums.size() - 2; index++)
        {
            int start = index + 1;
            int end =  nums.size() - 1;
            while(start < end)
            {
                int sum = nums[index] + nums[start] + nums[end];
                if(sum > target)
                end--;
                else
                start++;
                if(abs(sum - target) < abs(result - target))
                result = sum;
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
