#include<iostream>
#include<string>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int index, cur_index = -1, max_lenghth = 0;
      int char_set[256];//保存上次字符出现的位置
      memset( char_set, -1, sizeof( char_set ) );

    for( index = 0; index < s.size(); index++ )
    {
        if( char_set[ s[ index ] ] > cur_index )
        //字符重复出现
            cur_index = char_set[ s[ index ] ];
        if( index - cur_index > max_lenghth )
          max_lenghth = index - cur_index;
        char_set[ s[ index ] ] = index;
    }
      return max_lenghth;
    }
};

int main(int argc, char const *argv[]) {
  string s("sdfsgsdgf");

  return 0;
}
