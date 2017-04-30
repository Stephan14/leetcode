/*************************************************************************
	> File Name: q187.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  4/30 10:18:32 2017
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<map>


using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        vector<string> result;
        map<int, int> strTimesMap;
        if(s.size() < 10)
            return result;

        int curStr = 0;
        int i = 0;
        int mask = 0x7ffffff;
        while(i < 9)
            curStr = (curStr << 3) | (s[i++] & 7);

        while(i < s.size())
        {
            curStr = ((curStr & mask) << 3) | (s[i++] & 7);
            if(strTimesMap.find(curStr) != strTimesMap.end())
            {
                if(strTimesMap[curStr] == 1)
                    result.push_back(curStr);
                strTimesMap[curStr]++;
            }
            else
                strTimesMap[curStr] = 1;
        }

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
