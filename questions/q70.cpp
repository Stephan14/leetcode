/*************************************************************************
	> File Name: q70.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  7/15 18:04:19 2017
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        
        if(n == 1)
            return 1;
        else if(n == 2)
            return 2;
        else
            return climbStairs(n-1) + climbStairs(n-2); 

    }

};
