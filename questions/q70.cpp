/*************************************************************************
	> File Name: q70.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  7/15 18:04:19 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;
class Solution {
    public:
    int climbStairs(int n) {

        int* p = new int[n+1];
        p[1] = 1;
        p[2] = 2;

        for(int i = 3; i <= n; i++)
        {
            p[i] = p[i-1] + p[i-2];
        }
        
        return p[n];
    }

};
