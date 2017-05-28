/*************************************************************************
	> File Name: q336.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  5/27 10:24:18 2017
 ************************************************************************/

#include<iostream>
#include<string>
#include<unordered_map>
#include<set>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > palindromePairs(vector<string>& words) {
        
        vector<vector<int> > result;
        unordered_map<string, int> strPositionMap;
        set<int> lenMap;

        for(int index = 0; index < words.size(); index++)
        {
            strPositionMap[words[index]] = index;
            lenMap.insert(words[index].size());
        }

        for(int index = 0; index <words.size(); index++) 
        {
            string s = words[index];
            int len = words[index].size();
            reverse(s.begin(), s.end());
            //两个字符串长度相等情况下，如abc和cba
            if(strPositionMap.count(s) && strPositionMap[s] != index)
                result.push_back({index, strPositionMap[s]});//二维向量插入

            auto len_it = lenMap.find(len);
            for(auto it = lenMap.begin(); it != len_it; it++)
            {
                int d = *it;
                if(isVaild(s, 0, len - d - 1) && strPositionMap.count(s.substr(len - d)))    
                    result.push_back({index, strPositionMap[s.substr(len - d)]});
                if(isVaild(s, d, len -1) && strPositionMap.count(s.substr(0, d)))
                    result.push_back({strPositionMap[s.substr(0, d)], index});
            }
        }

        return result;
    }

    bool isVaild(string str, int left, int right)
    {
        while(left < right)
            if(str[left++] != str[right--])
                return false;
        return true;
    }
//    bool isPalindrome(string &word)
//    {
//        int len = word.size();
//        for(int index = 0; index < len / 2; index++)
//        {
//            if(word[index] != word[len - 1 - index])
//                return false;
//        }
//        return true;
//    }
};

int main()
{
    Solution s;
    string str = "abb";
    if(s.isPalindrome(str))
        cout << "is";
    else
        cout << "not";
}
