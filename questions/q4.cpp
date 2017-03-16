/*************************************************************************
	> File Name: q4.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  3/16 21:38:02 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(!nums2.empty())
            nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        if(nums1.size() % 2)
            return nums1[nums1.size() / 2];
        else 
            return (nums1[nums1.size() / 2] + nums1[nums1.size() / 2 - 1]) / 2; 
    }
};

int main()
{
    return 0;
}
