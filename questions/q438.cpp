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
        
        int len = p.size();
        string target = sortString(p);
        vector<int> result;

        if(s.size() < len)
            return result;

        for(int i = 0; i < s.size() - len + 1; i++)
        {
            if(sortString(s.substr(i, len)) == target)
                result.push_back(i);
        }

        return result;
    }


    string sortString(string str)
    {
        string result;
        int charRecord[26] = {0};
        for(auto &it : str)
            charRecord[it-'a']++;

        for(int i = 0; i < 26; i++)
            for(int j = 0; j < charRecord[i]; j++)
                result.push_back('a'+i);

        return result; 
    }
};

int main()
{
    string str1 = "abs";
    string str2 = "sba";
    Solution s;
    cout << s.sortString(str1);
    cout << s.sortString(str2);

}
