/*************************************************************************
	> File Name: q219.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  5/ 3 14:22:59 2017
 ************************************************************************/

#include<iostream>
#include<unordered_set>
#include<vector>


using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> preKValueSet; 
        if(k <= 0)
            return false;

        if(k >= nums.size())
            k = nums.size() - 1;

        for(int i = 0; i < nums.size(); i++)
        {
            if(i > k) 
                preKValueSet.erase(nums[i - k - 1]);
            if(preKValueSet.find(nums[i]) != preKValueSet.end())
                return true;
            preKValueSet.insert(nums[i]);
        }

        return false;
    }
};


