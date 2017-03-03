/*************************************************************************
	> File Name: q45.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  3/ 3 21:59:55 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {

        int res = 0, i = 0, cur = 0;
        int n = nums.size();

        while (cur < n - 1) {
            int pre = cur;
            while (i <= pre) {
                cur = max(cur, i + nums[i]);
                ++i;
            }
            ++res;
            if (pre == cur) return -1; // May not need this
        }
        return res;
    }
};

int main()
{
    return 0;
}
