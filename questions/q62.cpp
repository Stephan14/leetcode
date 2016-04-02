#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
  // int uniquePaths(int m, int n) {
  //     vector< vector< int > > v( m, vector<int>(n, 0) );
  //     return dfs( m-1, n-1, v);
  // }
  //
  // int dfs( int x, int y, vector< vector<int> > &v)
  // {
  //   int num = 0;
  //   if( x < 0 || y < 0 )
  //     return 0;
  //   if( x == 0 && y == 0 )
  //     return 1;
  //   return dfs( x, y-1, v ) + dfs( x-1, y, v );
  // }

    int uniquePaths(int m, int n){
      f = vector< vector<int> >(m, vector<int>(n, 0) );
      f[0][0] = 1;
      return dfs(m-1,n-1);

    }
public:
  vector< vector<int> > f;
  int dfs( int x, int y )
  {
    //终止条件
    if( x < 0 || y < 0 )
      return 0;
    if( x == 0 && y == 0 )
      return f[x][y];
    if( f[x][y] > 0 )
      return f[x][y];
    else
      return f[x][y] = dfs(x-1, y) + dfs( x, y-1);
  }
};


int main(int argc, char const *argv[]) {
  Solution s;
  cout<<s.uniquePaths( 23, 12);
  return 0;
}
