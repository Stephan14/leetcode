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
        //二分查找最小的元素的下标
        int start = 0;
        int end = nums.size()-1;
        while(start < end)
        {
            int mid = (start + end) / 2;
            if(nums[mid] > nums[end])
                start = mid + 1;
            else
                end = mid;//不是mid - 1
        }
        cout << "二分查找: start : " << start << " end: " << end <<endl;
        int smallest = start;
        start = 0;
        end = nums.size() - 1;
        while(start <= end)
        {
            int mid = (start + end) / 2;
            int realmid = (mid + smallest) % nums.size();//想像成一个环
            cout << "mid : " << mid << " realmid : " << realmid << endl;
            if(nums[realmid] == target)
                return realmid;
            else if(nums[realmid] < target)
                start = mid + 1;
            else
                end = mid - 1;
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
