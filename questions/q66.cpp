/*************************************************************************
	> File Name: q66.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  3/13 10:39:29 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int digit = 1;

        for(int index = digits.size()-1; index >= 0; index--)
        {
            int sum = digits[index] + digit;

            digit = sum / 10;
            digits[index] = sum % 10;
            if(sum > 9 && index == 0)
                digits.insert(digits.begin(), digit);
        }

        return digits;
    }
};

int main()
{
    return 0;
}

