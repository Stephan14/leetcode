/*************************************************************************
	> File Name: q438.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  6/14 15:49:18 2017
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>


using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        //使用两个数组来比较字符是否出现的一样
        //每个数组记录一段区域中字符出现的位置
        vector<int> result;
        vector<int> sMap(128, 0), pMap(128, 0);
        if(s.empty())
            return {};//返回空数组

        for(int i = 0; i < p.size(); i++)
        {
            ++sMap[s[i]];
            ++pMap[p[i]];
        }
        
        if(sMap == pMap)
            result.push_back(0);
        for(int i = p.size(); i < s.size(); i++)
        {
            ++sMap[s[i]];
            --sMap[s[i - p.size()]];
            if(sMap == pMap)
                result.push_back(i - p.size() + 1);
        }
        
        return result;
    }

};

int main()
{

}
