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

        if(m == 0 && n != 0)
        {
            nums1 = nums2;
            return;
        }

        int nums1Index = 0;
        int nums2Index = 0;
        int insert_num = 0;

        while(nums1Index < (m + insert_num) && nums2Index < n) //插入时数组长度在变化
        {
            if(nums1[nums1Index] > nums2[nums2Index])
            {
                nums1.insert(nums1.begin() + nums1Index, nums2[nums2Index]);
                nums2Index++;
                insert_num++;
            }
            nums1Index++;
        }

        if(nums2Index < n)
            nums1.insert(nums1.begin() + m + insert_num, nums2.begin() + nums2Index, nums2.end());
        if(nums1.size() > (m + n))
            nums1.erase(nums1.begin() + m + n, nums1.end());

        return;
    }
};

int main()
{
    return 0;
}
