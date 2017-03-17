/*************************************************************************
	> File Name: q78.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  3/17 20:35:58 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    //利用递归解决问题
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > result(1);//初始化空集

        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            int size = result.size();
            for(int j = 0; j < size; j++)
            {
                result.push_back(result[j]);
                result.back().push_back(nums[i]);
            }
        }
        
        return result;
    }
};

int main()
{
    return 0;
}
