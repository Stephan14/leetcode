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
    /*
    * 动态规划解决
    * int maximalRectangle(vector<vector<char> >& matrix) {
    *
    *   int result = 0;
    *   vector<int> left(matrix.size(), 0);
    *   vector<int> right(matrix.size(), matrix.size());
    *   vector<int> heights(matrix.size(), 0);
    *
    *   for(int i = 0; i < matrix.size(); i++)
    *   {
    *       int cur_left = 0;
    *       int cut_right = matrix.size();
    *
    *       for(int j = 0; j < matrix[i].size(); j++)    
    *       {
    *           if(matrix[i][j] == '1')
    *               heights[j]++;
    *           else
    *               heights[j] = 0;
    *       }
    *
    *       for(int j = 0; j < matrix[i].size(); j++)
    *       {
    *           if(matrix[i][j] == '1')
    *               left[j] = max(left[j], cur_left);
    *           else
    *           {
    *               left[j] = 0;
    *               cur_left = j + 1;
    *           }
    *       }
    *
    *       for(int j = matrix[i].size() - 1; j >= 0; --j)
    *       {
    *           if(matrix[i][j] == '1')
    *               right[j] = min(right[j], cur_right);
    *           else
    *           {
    *               right[j] = n;
    *               cur_right = j;
    *           }
    *       }
    *
    *       for(int j = 0; j < matrix[i].size(); j++)
    *       {
    *           result = max(result, heights[j] * (right[j] - left[j]));
    *       }
    *   }
    *   return result;
    * }
    *
    * */
};

int main()
{
    return 0;
}
