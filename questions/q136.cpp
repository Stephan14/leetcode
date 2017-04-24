/*************************************************************************
	> File Name: q136.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  4/24 19:09:49 2017
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int result = 0;
        int n = nums.size();
        for (int i = 0; i<n; i++)
        {
            result ^=nums[i];
        }
        return result;
    }
};
