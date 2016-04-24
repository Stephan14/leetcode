#include<iostream>
#include<string>
#include<unordered_set>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int index, length = 0, max_lenghth;

      unordered_set<char> visited;
      for( index = 0; index < s.size(); index++ )
      {
        if( visited.count( s[ index ] ) > 0 )
        {
          if( length > max_lenghth )
            max_lenghth = length;
          visited.clear();
          length = 0;
        }
        else
        {
          visited.insert( s[ index ] );
          length++;
        }
      }

      return length;
    }
};

int main(int argc, char const *argv[]) {
  string s("sdfsgsdgf");

  return 0;
}
