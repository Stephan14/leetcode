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
        int n = nums.size();

        for (int i=0; i<n; i++)  
        {  
            if (nums[i] > 0 && nums[i] < n)  
            {  
                //if (nums[i]-1 != i && nums[nums[i]-1] != nums[i])不用那么多条件就可以了。  
                //因为只要是已经到位了的元素即：nums[i]-1==i了，那么判断如果有重复元素  
                //两个位置交换就最好考虑好两个位置出现的可能情况。考虑问题全面，两个条件都考虑好。  
                //update:增加i!=nums[i]表示i位置没到位，nums[nums[i]-1] != nums[i]表示nums[i]-1位置没到位，两个位置都判断也很好的。  
                if (nums[nums[i]-1] != nums[i])  
                {  
                    swap(nums[nums[i]-1], nums[i]);  
                    i--;  
                }  
            }  
        }  

        for (int j=0; j<n; ++j)  
        if (nums[j]-1 != j)  
        return j+1;  

        return n+1; 
    }
};

