/*************************************************************************
	> File Name: q217.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  5/ 3 13:25:58 2017
 ************************************************************************/

#include<iostream>
#include<set>
#include<vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> numTimesMap;
        for(auto &num : nums)
        {
            if(numTimesMap.find(num) != numTimesMap.end())
                return true;
            else
                numTimesMap.insert(num);
        }
        return false;
    }
};
