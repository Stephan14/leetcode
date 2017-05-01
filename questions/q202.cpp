/*************************************************************************
	> File Name: q202.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  5/ 1 10:14:13 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        
        int tempN = 0;
        int sourceN = n;
        vector<int> sumRecord;
        while(n != 0)
        {
            while(n != 0) 
            {
                int digit = n % 10;
                tempN += digit * digit;
                n = n / 10;
            }

            if(tempN == 1)
                return true;
            else
            {
                vector<int>::iterator it = find(sumRecord.begin(), sumRecord.end(), tempN);
                if(it == sumRecord.end())
                    sumRecord.push_back(tempN);
                else
                    return false;
                n = tempN;
                tempN = 0;
            }
        }

        return false;
    }
};
