/*************************************************************************
	> File Name: q85.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  3/23 16:02:41 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        int result = 0;

        vector<int> heights;

        for(int i = 0; i < matrix.size(); i++)
        {
            heights.resize(matrix.size());
            for(int j = 0; j < matrix[i].size(); j++)
            {
                heights[j] = matrix[i][j] == '1' ? (heights[j] + 1) : 0;
            }
            //一行一行进行计算
            result = max(result, largestRectangleArea(heights));
        }
    }
    int largestRectangleArea(vector<int> &heights){
        
        int result = 0;
        stack<int> s;
        heights.push_back(0);

        for(int i = 0; i < heights.size(); i++)
        {
            if(s.empty() || heights[s.top()] <= heights[i])
                s.push( i );
            else
            {
                int tmp = s.top();
                s.pop();
                result = max(result, heights[tmp] * ( s.empty() ? i : (i - s.top() - 1)));
            }
        }
        
        return result;
    }
};

int main()
{
    return 0;
}
