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
    vector<vector<int> > subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        vector<int> vec;
        subsetsWithDup(res, nums, vec, 0);
        return res;
    }
    private:
    void subsetsWithDup(vector<vector<int> > &res, vector<int> &nums, vector<int> &vec, int begin) {

        res.push_back(vec);
       
        for(int i = 0; i < vec.size(); i++)
            cout << " " << vec[i] << " ";
        cout << endl;

        for(int i = begin; i != nums.size(); ++i)
            if(i == begin || nums[i] != nums[i - 1]) {//排序去重
                vec.push_back(nums[i]);
                subsetsWithDup(res, nums, vec, i + 1);
                vec.pop_back();
        }
    }
};

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);

    Solution s;
    vector<vector<int> > res = s.subsetsWithDup(v);
    cout << res.size();
    return 0;
}
