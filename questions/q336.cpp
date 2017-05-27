/*************************************************************************
	> File Name: q336.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  5/27 10:24:18 2017
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > palindromePairs(vector<string>& words) {
        
        vector<vector<int> > result;

        for(int i = 0; i < words.size(); i++)
            for(int j = 0; j < words.size(); j++)
        {
            string str(words[i]);
            str.append(words[j]);
            if(i != j && isPalindrome(str))
            {
                vector<int> tmp;
                tmp.push_back(i);
                tmp.push_back(j);
                result.push_back(tmp);
            }
        }

        return result;
    }

    bool isPalindrome(string &word)
    {
        int len = word.size();
        for(int index = 0; index < len / 2; index++)
        {
            if(word[index] != word[len - 1 - index])
                return false;
        }
        return true;
    }
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
