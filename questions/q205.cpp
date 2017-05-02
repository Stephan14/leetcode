/*************************************************************************
	> File Name: q205.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  5/ 2 09:14:00 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if(s.size() != t.size())
            return false;

        int i = 0;
        vector<char> charArray(256, ' ');
        while(i < s.size())
        {
            if(charArray[s[i]] == ' ' && charArray[t[i]] == ' ')
            {
                charArray[s[i]] = t[i];
                charArray[t[i]] = s[i];
            }
            else if((charArray[s[i]] != ' ' && charArray[s[i]] != t[i]) ||
                    (charArray[t[i]] != ' ' && charArray[t[i]] != s[i]))
                    return false;

            i++;
        }

        return true;
    }
};

int main()
{
    Solution S;
    string s = "foo";
    string t = "bar";

    if(S.isIsomorphic(s, t))
        cout << "tes";
    else
        cout << "sfdsf";
    return 0;
}
