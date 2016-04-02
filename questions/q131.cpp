/*深度优先搜索*/
#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;

class Solution {
public:

    void dfs(string s, vector<string> &path, vector<vector<string> > &res)
    {
        //终止条件
        //收敛条件
        if(s.size() < 1)
        {
            res.push_back(path);
            return;
        }
        for(int i = 0; i < s.size(); i++)
        {
            int begin = 0;
            int end = i;
            while(begin < end)
            {
                if(s[begin] == s[end])
                {
                    begin++;
                    end--;
                }
                else
                    break;
            }

            if(begin >= end)//bool isPalindrome = true;
            {
                //执行所有可能的扩展动作
                path.push_back(s.substr(0,i+1));
                cout<<"s.substr(0,i+1)"<<s.substr(0,i+1)<<endl;
                dfs(s.substr(i+1),path,res);
                path.pop_back();
            }
        }
    }
    vector<vector<string> > partition(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<string> > res;
        vector<string> path;
        dfs(s,path,res);
        return res;
    }
};


int main(int argc, char const *argv[]) {
  Solution s;
  // cout<<s.isPalindrome("abacba")<<endl;
  // string str = "1234567";
  // cout<<str.substr(1,4);
  string str="aab";
  vector<vector<string> > v = s.partition( str );
  int i= 0, j = 0;
  for( ; i < v.size(); i++ )
  {
    for(j = 0; j < v.at(i).size(); j++ )
      cout<< v[i][j]<<" ";
    cout<<endl;
  }
  cout<<v[0][0]<<" "<<v[0][1]<<endl;
  return 0;
}
