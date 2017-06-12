/*************************************************************************
	> File Name: q409.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  6/10 21:13:12 2017
 ************************************************************************/

#include<iostream>
#include<string>
#include<map>

using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
       
        int charTimes[256] = {0};
        int maxLen = 0;
        bool flag = false;

        for(auto &it : s)
            charTimes[it]++;

        for(int i = 0; i < 256; i++)
        {
            maxLen += charTimes[i];
            if(charTimes[i] != 0 && charTimes[i] % 2) //取奇数长度中最大的偶数长度
            {
                maxLen -= 1;
                flag = true;
            }
        }

        return flag ? 1 + maxLen : maxLen;
    }
};

