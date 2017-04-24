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
        for(auto &oneNum : nums)
            result ^= oneNum;
        return result;
    }
};
