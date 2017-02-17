/*************************************************************************
	> File Name: q33.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  2/17 08:44:55 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        if(nums.empty())
        return -1;

        int l = 0, r = nums.size()-1;
        while(l<=r)
        {
            int m = (l+r)/2;
            if(nums[m] == target) return m;
            if(nums[m]>= nums[l])
            {
                if(nums[l]<=target && target< nums[m])
                r=m-1;
                else
                l = m+1;
            }
            else
            {
                if(nums[m]< target && target<=nums[r])
                l = m+1;
                else
                r = m-1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    int target = 3;
    cout << s.search(v, target);
    return 0;
}
