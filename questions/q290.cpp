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
        
        map<char, int> p2s;
        map<string, int> s2p;
        int i = 0, len = pattern.size();
        istringstream in(str);

        for(string word; in >> word; i++)//for 循环中执行完初始化之后，执行条件判断
        {
            if(i == len || p2s[pattern[i]] != s2p[word])
                return false;
            p2s[pattern[i]] = s2p[word] = i + 1;
            cout << i << ":" << word << endl;
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
