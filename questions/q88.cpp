/*************************************************************************
	> File Name: q88.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  3/30 21:15:09 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i=m-1;
        int j=n-1;
        int k = m+n-1;

        while(i >=0 && j>=0) //两个数组合并，从后往前
        {
            if(nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }
        while(j>=0)
            nums1[k--] = nums2[j--];
    }
};

int main()
{
    return 0;
}
