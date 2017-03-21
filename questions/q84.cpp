/*************************************************************************
	> File Name: q84.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  3/21 21:28:21 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;

        for (int i = 0; i < heights.size(); ++i) {
            //遍历寻找局部峰值
            if (i + 1 < heights.size() && heights[i] <= heights[i + 1]) {
                continue;
            }
            //向前遍历所有值
            int minH = heights[i];
            for (int j = i; j >= 0; --j) {
                minH = min(minH, heights[j]);
                int area = minH * (i - j + 1);
                result = max(result, area);
            }
        }
        return result;
    }

};

int main()
{
    return 0;
}
