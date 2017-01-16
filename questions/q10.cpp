/*************************************************************************
	> File Name: q10.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  1/15 15:53:50 2017
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    int maxArea(vector<int>& height) {

        size_t i = 0;
        size_t j = height.size()-1;
        int mastWater = 0;

        while(i < j)
        {
            if(height[i] < height[i+1])
            {
                i++;
                int tempMastWater = (j-i)*min(height[i], height[j]);  
                if(tempMastWater > mastWater)
                mastWater = tempMastWater;
            }
            else if(height[j] < height[j-1])
            {
                j--; 
                int tempMastWater = (j-i)*min(height[i], height[j]);  
                if(tempMastWater > mastWater)
                mastWater = tempMastWater;
            }
            else
            {
                i++;
                j--;
            }
        }
        return mastWater;
    }
};

int main()
{

}
