/*************************************************************************
	> File Name: q80.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  3/20 19:59:32 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       
        if(nums.size() <= 2)
            return nums.size();
        
        int index = 1;
        int pre = 0;
        int count  = 1;
        //使用两个指针：快指针和慢指针
        while(index < nums.size())
        {
            if(nums[index] == nums[pre] && count == 0)
                index++;
            else
            {
                if(nums[index] == nums[pre])
                    count--;
                else
                    count = 1;
                nums[++pre] = nums[index++];
            }
        }
        return pre + 1;
    }
};

int main()
{
    return 0;
}
