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

        int n = nums.size();
        int result = nums[0];

        for(int i=1;i<n;i++)
        {
            result = result ^ nums[i];  /* Get the xor of all elements */
        }
        return result;
    }
};
