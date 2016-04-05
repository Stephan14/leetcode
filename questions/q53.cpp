#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int i, j, max = INT_MIN, temp_max = 0;
      for( i = 0; i < nums.size(); i++ )
      {
        temp_max = findmax( temp_max + nums[i], nums[i] );
        max = findmax( temp_max, max );
      }
      return max;
    }

    int findmax( int a, int b )
    {
      return a>b ? a : b;
    }
    //查找三个数中的最大值
    // int findmax( int a, int b, int c )
    // {
    //   if( a < b ) swap( a, b);
    //   if( a < c ) swap( a, c);
    //   if( b < c ) swap( b, c);
    //
    //   return a;
    // }
    //交换两个数
    // void swap( int &a, int &b )
    // {
    //   int temp = a;
    //   a = b;
    //   b = temp;
    // }
};

int main(int argc, char const *argv[]) {
  /* code */
  Solution s;
  vector< int > v;
  v.push_back( 1 );
  v.push_back( -1 );
  v.push_back( 1 );
  cout<<s.maxSubArray( v );
  return 0;
}
