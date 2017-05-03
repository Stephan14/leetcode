/*************************************************************************
	> File Name: q217.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  5/ 3 13:25:58 2017
 ************************************************************************/

#include<iostream>
#include<map>
#include<vector>


using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() < 2)
            return false;

        map<int, int> numTimesMap;
        for(auto &num : nums)
        {
            if(numTimesMap.find(num) != numTimesMap.end())
                numTimesMap[num]++;
            else
                numTimesMap[num] = 1;
            if(numTimesMap[num] > 1)
                return true;
        }

        return false;
    }
};
