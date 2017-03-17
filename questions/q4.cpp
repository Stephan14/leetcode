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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)   
    {
        int m = nums1.size(), n = nums2.size();
        return (findKthofTwoSortedArraysh(nums1, nums2, (m + n + 1) / 2) + findKthofTwoSortedArrays(nums1, nums2, (m + n + 2) / 2)) / 2.0;
    }
private:
    //两个数组的二分查找
    double findKthofTwoSortedArrays(vector<int>& num1, vector<int>& num2, int k)
    {
        int m1 = num1.size();
        int m2 = num2.size();

        if(m1 > m2)//保证第一个参数的数组长度小于第二个参数的长度
            return findKthofTwoSortedArrays(num2, num1, k);
        if(m1 == 0)
            return num2[k-1];
        if(k == 1)
            return min(num1[0], num2[0]);

        int i = min(m1, k / 2);
        int j = min(m2, k / 2);
        
        if(num1[i-1] > num2[j-1])
            return findKthofTwoSortedArrays(num1, vector<int>(num2.begin() + j, num2.end()), k - j );
        else 
            return findKthofTwoSortedArrays(vector<int>(num1.begin() + i, num1.end()), num2, k - i);
            
        return 0;
    }
};

int main()
{
    return 0;
}
