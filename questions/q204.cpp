/*************************************************************************
	> File Name: q204.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  5/ 1 11:06:31 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Solution {
    public:

    int countPrimes(int n) {
    
        if(n <= 2)
            return 0;
        int counter = 1;
        vector<bool> passed(n, false);

        int upper = sqrt(n);
        for(int i = 3; i < n; i += 2)
        {
            if(!passed[i]) 
            {
                counter++;
                if(i > upper)
                    continue;
                for(int j = i * i; j < n; j += i)
                    passed[j] = true;
            }
        }

        return counter;
    }
};

