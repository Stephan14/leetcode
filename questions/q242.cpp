/*************************************************************************
	> File Name: q242.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  5/ 7 19:48:31 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
    
        if(strSort(s) == strSort(t))
            return true;
        else
            return false;
    }

private:
    //基于基数排序
    string strSort(string &str)
    {
        int strTime[26] = {0};
        string strToReturn(str.size(), 'a');

        for(int i = 0; i < str.size(); i++)
            strTime[str[i] - 'a']++;
        
        int postion = 0;
        for(int i = 0; i < 26; i++)
            for(int j = 0; j < strTime[i]; j++)
                strToReturn[postion++] += i;

        return strToReturn;
    }
};
