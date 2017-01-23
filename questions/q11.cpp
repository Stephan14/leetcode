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
            int  newWater = (j-i)*min(height[i], height[j]);
            mastWater = max( mastWater,newWater );
            if(height[i] < height[j])
            {
                int x = i;
                while(x < j && height[x] <= height[i])
                    x++;
                i = x;
            }
            else
            {
                int x = j;
                while(i < x && height[x] <=height[j])
                   x--;
                j = x;
            }
        }
        return mastWater;
    }

    int maxArea(vector<int> &h) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int res=0;
            int n = h.size();
            int l=0,r=n-1;
            while(l<r)
            {
                res=max(res,min(h[l],h[r])*(r-l));
                if (h[l]<h[r])
                {
                    int k=l;
                    while(k<r&&h[k]<=h[l])
                        k++;
                    l=k;
                    }
                else
                {
                    int k=r;
                    while(k>l&&h[k]<=h[r])
                        k--;
                    r=k;
                 }
            }
            return res;
        }
};

int main()
{
    Solution s;
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    cout << s.maxArea( v );
}
