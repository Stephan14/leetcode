/*************************************************************************
	> File Name: q204.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  5/ 1 11:06:31 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
    public:
    bool isPrime(int n)    
    {
        if(n < 2)            
            return false;

        for (int i=2;i*i<=n;i++)   
        {
            if(n % i == 0)
            return false;
        }

        return true;
    }

    int countPrimes(int n) {
        
        int counter = 0;

        for(int i = 0; i < n; i++)
            if(isPrime(i))   
                counter++;

        return counter;
    }
};

