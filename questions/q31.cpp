/*************************************************************************
	> File Name: q31.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  2/16 11:01:39 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
    void nextPermutation(vector<int>& nums) {

        if(nums.empty())
        return;

        int last = -1;
        for(int i = 0; i < nums.size()-1; i++)
        {
            if(nums[i] < nums[i+1])
            last = i;    
        }

        if(last == -1)
        {
            sort(nums.begin(),nums.end());
            return;
        }

        int max = -1;
        for(int i = nums.size()-1; i >= 0; i--)
        {
            if(nums[i] > nums[last])
            {
                max = i;
                break;
            } 
        }

        if(max != -1)
        {
            swap(nums[last], nums[max]);
            reverse(nums.begin()+last+1, nums.end());
        }
    }
};

int main()
{
    return 0;
}
