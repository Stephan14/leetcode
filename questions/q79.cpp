/*************************************************************************
	> File Name: q79.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  3/19 19:51:39 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
        
        if(word.empty())
            return true;
        if(board.empty() || board[0].empty())
            return false;
        
        vector<vector<bool> > visited(board.size(), vector<bool>(board[0].size(), false));

        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[i].size(); j++)
        {
            cout << i <<" : " << j << endl;
            if(DFSsearch(i, j, 0, board, word, visited)) 
                return true;
        }

        return false;
    }

    bool DFSsearch(int i, int j, int index, vector<vector<char> >&board, string word, vector<vector<bool> >& visited )
    {
        if(index == word.size())
            return true;
        if(i < 0 || j < 0 || i >= board.size() || j >= board[i].size() || word[index] != board[i][j] || visited[i][j])
            return false;
        visited[i][j] = true;//递归调用之前的处理
        bool res =  DFSsearch(i - 1, j, index + 1, board, word, visited) ||
                    DFSsearch(i, j - 1, index + 1, board, word, visited) ||
                    DFSsearch(i + 1, j, index + 1, board, word, visited) ||
                    DFSsearch(i, j + 1, index + 1, board, word, visited);
        visited[i][j] = false;//递归调用之后的回溯

        return res;
    }

};

int main()
{
    vector<vector<char> > board;
    char *str1 = "ABCE";
    char *str2 = "SFCS";
    char *str3 = "ADEE";

    board.push_back(vector<char>(str1, str1 + strlen(str1)));
    board.push_back(vector<char>(str2, str2 + strlen(str2)));
    board.push_back(vector<char>(str3, str3 + strlen(str3)));

    string word = "ABCCED";
    Solution s;
    cout << s.exist(board, word);
    return 0;
}
