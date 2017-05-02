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
        
        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
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
