/*************************************************************************
	> File Name: q187.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  4/30 10:18:32 2017
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>


using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        vector<string> result;
        unordered_map<string, int> strTimesMap;
        if(s.size() < 10)
            return result;

        for(int i = 0; i <= s.size() - 10; i++) 
        {
            string str = s.substr(i, 10);
            if(strTimesMap.find(str) == strTimesMap.end())
                strTimesMap[str] = 1;
            else
                strTimesMap[str]++;
        }

        for(auto it = strTimesMap.begin(); it != strTimesMap.end(); it++)
            if(it->second > 1)
                result.push_back(it->first);

        return result;
    }
};


int main()
{
    Solution S;
    string s = "AAAAAAAAAAA";
    vector<string> result = S.findRepeatedDnaSequences(s);
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
    return 0;
}
