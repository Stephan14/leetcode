/*************************************************************************
	> File Name: q18.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  2/15 10:37:18 2017
 ************************************************************************/

#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector< vector<int> > fourSum(vector<int>& nums, int target) {
        
        vector< vector<int> > result;
        
        if(nums.size() < 4)
            return result;
        sort(nums.begin(), nums.end());

        for(int index1 = 0; index1 < nums.size(); index1++)
        {
            int target_3 = target - nums[index1];

            for(int index2 = index1+1; index2 < nums.size(); index2++)
            {
                int target_2 = target_3 - nums[index2];  
                int front = index2+1;
                int back = nums.size()-1;

                while(front < back)
                {
                    if(nums[front]+nums[back] < target_2)
                        front++;
                    else if(nums[front]+nums[back] > target_2)
                        back--;
                    else
                    {
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = nums[index1];
                        quadruplet[1] = nums[index2];
                        quadruplet[2] = nums[front];
                        quadruplet[3] = nums[back];
                        result.push_back(quadruplet);
                        while(front < back && nums[front] == quadruplet[2]) front++;
                        while(front < back && nums[back] == quadruplet[3]) back--;
                    }
                }
                while(index2+1 < nums.size() && nums[index2+1] == nums[index2]) index2++;//没有改变index的值，因为for循环中可以改变
            }
            while(index1+1 < nums.size() && nums[index1+1] == nums[index1]) index1++;
        }
        return result;
    }
};

int main()
{
    return 0;
}
