/*************************************************************************
	> File Name: q49.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  4/12 09:31:40 2017
 ************************************************************************/

#include<iostream>
#include<unordered_map>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {

        vector<vector<string> > result;
        if(strs.empty())
            return result;

        unordered_map<string, multiset<string> > words_map;
        for(string str : strs)
        {
            string tmp = strSort(str);
            words_map[tmp].insert(str);
        }

        for(auto &word : words_map)
        {
            vector<string> anagrams(word.second.begin(), word.second.end());
            result.push_back(anagrams);
        }
        
        return result;
    }

    private:
    string strSort(string str)
    {
        int count[26] = {0}, len = str.length();
        for(int index  = 0; index < len; index++) 
            count[str[index] - 'a']++; 

        int p = 0;
        string strToReturn(len, 'a');
        for(int indexCount = 0; indexCount < 26; indexCount++)
            for(int index = 0; index < count[indexCount] ; index++)
                strToReturn[p++] += indexCount; 

        return strToReturn;
    }
};

int main()
{
    return 0;
}
