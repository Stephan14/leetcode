/*************************************************************************
	> File Name: q39.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  2/26 16:44:16 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        vector<int> com;

        sort(candidates.begin(), candidates.end()); //排序去重
        combinationSum(result, com, candidates, target, 0); 
        return result;
    }
private:

    void combinationSum(vector<vector<int> > &res, vector<int> &combination, vector<int> &candidates, int target, int begin)
    {
        if( !target ) 
        {
            res.push_back( combination );
            return;
        }
        
        for(int i = begin; i < candidates.size(); i++)
        {
            if(i == begin || candidates[i] != candidates[i - 1])
            {
                combination.push_back( candidates[i]);
                combinationSum(res, combination, candidates, target - candidates[i], i + 1);
                combination.pop_back();
            }
        }

        return;
    }

};

int main()
{
    return 0;
}
