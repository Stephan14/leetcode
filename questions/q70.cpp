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

        int record = n;
        return climbStairs(n, record, p);


    }

    int climbStairs(int n, int& record, int array[])
    {
        if(n == 1)
        {
            record = 1;
            return array[1];

        }
        else if(n == 2)
        {
            record = 2;
            return array[2];

        }
        else if(n > record)
        return array[n];
        else
        {
            record = n - 1;
            array[n] = climbStairs(n-1, record, array) + climbStairs(n-2, record, array);
            return array[n];

        }

    }
};
