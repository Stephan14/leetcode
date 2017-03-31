/*************************************************************************
	> File Name: q90.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  3/31 09:24:06 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        vector<int> aSet;
        vector<vector<int> > result;
        
        getSubsetsWithDup(nums, 0, aSet, result);

        return result;
    }
    
    void getSubsetsWithDup(vector<int>& nums, int index, vector<int>& oneSet, vector<vector<int> >& allSets)
    {
        if(index == nums.size())    
            return;
        allSets.push_back(oneSet);
        for(int i = index; i < nums.size(); i++)
        {
            oneSet.push_back(nums[index]);
            getSubsetsWithDup(nums, index + 1, oneSet, allSets);
            oneSet.pop_back();
        }
    }
};

int main()
{
    return 0;
}
