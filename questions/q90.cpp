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
        allSets.push_back(oneSet);
        for(int i = 0; i < oneSet.size(); i++)
        {
            cout << " " << oneSet[i] << "\t";
        }
        cout << endl;

        for(int i = index; i < nums.size(); i++)
        {
            oneSet.push_back(nums[i]);
            getSubsetsWithDup(nums, i + 1, oneSet, allSets);
            oneSet.pop_back();
        }
    }
};

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    Solution s;
    vector<vector<int> > res = s.subsetsWithDup(v);
    cout << res.size();
    return 0;
}
