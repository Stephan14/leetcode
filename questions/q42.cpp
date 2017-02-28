/*************************************************************************
	> File Name: q42.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  2/28 22:13:09 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
     
        int left = 0, right = height.size() - 1;
        int maxleft = 0, maxright = 0;
        int result = 0;
        //类似于快排，从两侧向中间移动
        while(left < right)
        {
            if(height[left] <= height[right]) 
            {
                if(height[left] > maxleft )
                    maxleft = height[left];
                else
                    result += maxleft - height[left];
                left++;
            }
            else
            {
                if(height[right] > maxright) 
                    maxright = height[right];
                else
                    result += maxright - height[right];
                right--;
            }
        }
        return result;
    }
};

int main()
{
    
    return 0;
}
