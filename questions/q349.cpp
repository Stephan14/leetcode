/*************************************************************************
	> File Name: q349.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  5/31 23:30:07 2017
 ************************************************************************/

#include<iostream>
#include<set>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> record(nums1.begin(), nums1.end()), result;
        for(auto &it : nums2)
        {
            if(record.count(it))
                result.insert(it);
        }
        return vector<int>(result.begin(), result.end());
    }
};
