/*************************************************************************
	> File Name: q290.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  5/ 9 10:06:17 2017
 ************************************************************************/

#include<iostream>
#include<sstream>
#include<map>
#include<string>

using namespace std;

class Solution {
    public:
    bool wordPattern(string pattern, string str) {
        istringstream strcin(str);
        string s;
        vector<string> vs;
        while(strcin >> s) vs.push_back(s);
        if (pattern.size() != vs.size()) return false;
        map<string, char> s2c;
        map<char, string> c2s;
        for (int i = 0; i < vs.size(); ++i) {
            if (s2c[vs[i]] == 0 && c2s[pattern[i]] == "") { 
                s2c[vs[i]] = pattern[i]; 
                c2s[pattern[i]] = vs[i]; 
                continue; 
            }
            if (s2c[vs[i]] != pattern[i]) return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    string p1 = "abba";
    string s1 = "dog cat cat dog";

    if(s.wordPattern(p1, s1))
        cout << "OK" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
