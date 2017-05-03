/*************************************************************************
	> File Name: q217.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  5/ 3 13:25:58 2017
 ************************************************************************/

#include<iostream>
#include<set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();
    }
};
