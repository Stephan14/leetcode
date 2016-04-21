#include<vector>
#include<unordered_set>

class Solution {
public:
    vector<string> temp_path;
    vector<vector<string>> result_path;

    void GeneratePath(unordered_map<string, unordered_set<string>> &path, const string &start, const string &end)
    {
        temp_path.push_back(start);
        if(start == end)
        {
          vector<string> ret = temp_path;
          reverse(ret.begin(),ret.end());
          result_path.push_back(ret);
          return;
        }

        for(auto it = path[start].begin(); it != path[start].end(); ++it)
        {
              GeneratePath(path, *it, end);
              temp_path.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord,
      unordered_set<string> &wordList)
    {

      unordered_set<string> current_step;
      unordered_set<string> next_step;
      unordered_map< string, unordered_set<string> > path;
      unordered_set<string> unvisited = wordList;

      if( wordList.find( beginWord ) == wordList.end() || wordList.find( endWord ) == wordList.end() )
        return  result_path;
      if( unvisited.count( beginWord ) > 0)
        unvisited.erase( beginWord );
      current_step.insert( beginWord );

      while( current_step.count( endWord ) == 0 && unvisited.size() > 0 )
      {
        //遍历当前set中的元素
        for( auto cur = current_step.begin(); cur != current_step.end(); ++cur )
        {
          int i;
          string word = *cur;
          for( i = 0; i < word.size(); i++ )
          {
            int j ;
            string temp = word;
            for( j = 0; j < 26; j++ )
            {
              if( temp[i] == 'a'+j )
                continue;
              temp[i] = 'a'+j;
              if( unvisited.count( temp ) > 0 )
              {
                next_step.insert( temp );
                path[ temp ].insert( word );
              }
            }
          }
        }

        if( next_step.empty() )
          break;
        for( auto it = next_step.begin(); it != next_step.end(); ++it )
          unvisited.erase( *it );

        current_step = next_step;
        next_step.clear();
      }

      if( current_step.count( endWord ) > 0 )
        GeneratePath(path, endWord, beginWord);

      return result_path;
    }
};

int main(int argc, char const *argv[]) {

  return 0;
}
