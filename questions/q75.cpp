/*************************************************************************
	> File Name: q75.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  3/16 17:23:49 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        //类似于快速排序，也可以使用计数排序扫描两遍
        int red = 0;
        int blue = nums.size() - 1;

        for(int i = 0; i < nums.size(); i++) 
        {
            if(nums[i] == 0) 
                swap(nums[i], nums[red++]);   
            else if(nums[i] == 2)
                swap(nums[i--], nums[blue--]);
        }
    }
};

int main()
{
    Solution s;
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    s.sortColors(v);
    cout << v[0] << v[1] << endl;
    return 0;
}
