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

        int i = m - 1, j = n - 1, tar = m + n - 1;
        while (j >= 0) {
            nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }

    }
};

int main()
{
    return 0;
}
