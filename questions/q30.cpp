/*************************************************************************
	> File Name: q30.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  4/ 7 14:27:31 2017
 ************************************************************************/

#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findsubstring(string s, vector<string>& words) {

        vector<int> result;
        if(s.empty() || words.empty() || words.size() * words[0].size() > s.size())
            return result;
        
        unordered_map<string, int> target_map;
        for(auto &word : words)
            ++target_map[word];
        
        int num_words = words.size();
        int char_word = words[0].size();
        //遍历源字符串查找而不是目标数组
        for(int index = 0; index <= s.size() - num_words * char_word; index++ )
        {
            unordered_map<string, int>target_exit;
            int j;
            for(j = 0; j < num_words; j++)
            {
                string target = s.substr(index + j * num_words, num_words);
                if(target_map.find(target) == target_map.end())
                    break;
                ++target_exit[target];
                if(target_map[target] < target_exit[target]) 
                    break;
            }

            if(j == num_words)
            {
                cout << "tset" << endl;
                result.push_back(index);
            }
        }

        return result;
    }
};


int main()
{
    Solution so;
    string s = "barfoothefoobarman";
    vector<string> words;
    words.push_back("foo");
    words.push_back("bar");
    vector<int> res = so.findsubstring(s, words);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
    return 0;
}
