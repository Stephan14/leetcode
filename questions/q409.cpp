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
       
        map<char, int> charTimes;
        int maxLen = 0;
        bool flag = false;
        for(auto &it : s)
            if(charTimes.find(it) != charTimes.end()) 
                charTimes[it]++;
            else
                charTimes[it] = 1;

        for(auto &it : charTimes)
        {    
            maxLen += it.second;
            if(it.second % 2) //取奇数长度中最大的偶数长度
            {
                maxLen -= 1;
                flag = true;
            }
        }

        return flag ? 1 + maxLen : maxLen;
    }
};

