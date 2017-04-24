/*************************************************************************
	> File Name: q136.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  4/24 19:09:49 2017
 ************************************************************************/

#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
       
        unordered_map<int, int> numsMap;
        for(auto num : nums)
        {
            if(numsMap.find(num) == numsMap.end()) 
                numsMap[num] = 1;
            else 
                numsMap[num]++;
        }

        for(auto &oneTimeNum : numsMap)
            if(oneTimeNum.second == 1)
                return oneTimeNum.first;
        return 0;
    }
};
