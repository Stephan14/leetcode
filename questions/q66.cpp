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
    
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] == 9) digits[i] = 0;
            else {
                digits[i] += 1;
                return digits;
            }
        }
        if (digits.front() == 0) digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main()
{
    return 0;
}

