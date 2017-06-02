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
    //使用双指针
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int nums1Index = 0, nums2Index = 0;
        vector<int> result;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        while(nums1Index < nums1.size() && nums2Index < nums2.size())
        {
            if(nums1[nums1Index] < nums2[nums2Index])
                nums1Index++;
            else if(nums1[nums1Index] > nums2[nums2Index])
                nums2Index++;
            else 
            {
                if(result.empty() || result.back() != nums1[nums1Index])
                    result.push_back(nums1[nums1Index]);
                nums1Index++, nums2Index++;
            }
        }

        return result;
    }    
};
