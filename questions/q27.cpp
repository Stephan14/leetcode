/*************************************************************************
	> File Name: q27.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  2/16 10:22:24 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) 
            return 0;
        
        int len = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != val) 
                nums[len++] = nums[i];
        }
        return len;
    }
};

int main()
{

    return 0;
}
