/*************************************************************************
	> File Name: q15.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  2/ 5 09:29:30 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector< vector <int> > result;
        if(nums.size() < 3)
            return result;
        sort(nums.begin(), nums.end());//从小到大排序

        for(int index = 0; index < nums.size()-2; index++)
        {
            if(index == 0 || (index > 0 && nums[index] != nums[index-1])) // 去除重复的情况
            {
                int i = index + 1;
                int j = nums.size() - 1;
                while(i < j)//类似于快速排序的代码格式
                {
                    if(-nums[index] == (nums[i] + nums[j]))
                    {
                        vector<int> temp;
                        temp.push_back(nums[index]);
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        result.push_back(temp);
                        while(i < j && nums[i] == nums[i+1]) i++;//注意判断边界条件
                        while(i < j && nums[j] == nums[j-1]) j--;
                        i++,j--;
                    }
                    else if(i < j && -nums[index] <= (nums[i] + nums[j]))
                        j--;
                    else if(i < j && -nums[index] >= (nums[i] + nums[j]))
                        i++;
                }    
            }
       }
        return result;
    }
};
int main()
{
    vector<int> t;
    t.push_back(-1);
    t.push_back(0);
    t.push_back(1);
    t.push_back(2);
    t.push_back(-1);
    t.push_back(-4);
    Solution s;
    vector< vector <int> > v;
    v =  s.threeSum(t);
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = 0; j < v[i].size(); j++ )
            cout << v[i][j];
        cout << "\n";
    }
    return 0;
}
