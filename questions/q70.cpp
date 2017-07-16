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

        if(n == 1)
            return 1;

        int first = 1;
        int second = 2;
        for(int i = 3; i <= n; i++)
        {
            int third = first + second;
            first = second;
            second = third;
        }

        return second;
    }

};
