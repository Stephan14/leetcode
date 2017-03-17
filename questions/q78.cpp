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
        vector<vector<int> > result;
        vector<int> out;

        if(nums.empty())   
        {
            result.push_back(nums);  
            return result;
        }

        sort(nums.begin(), nums.end());
        getSubsets(nums, 0, out, result);
        return result;
    }
private:
    void getSubsets(vector<int>nums, int index, vector<int> &out, vector<vector<int> > &res)
    {
        res.push_back(out);    
        for(int i = index; i < nums.size(); i++)
        {
            out.push_back(nums[i]);
            getSubsets(nums, i+1, out, res);
            out.pop_back();
        }
    }
};

int main()
{
    return 0;
}
