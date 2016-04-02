#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector< vector< int > > v( m, vector<int>(n) );
        int sum = 0;
        int i , j;
        for( i = 0; i < m; i++ )
          for( j = 0; j < n; j++ )
            v[i][j] = 0;
        sum = dfs( m, n, v);
        return sum;
    }

    int dfs( int x, int y, vector< vector<int> > &v)
    {
      int num = 0;
      if( x < 0 || y < 0 )
        return 0;
      if( x == 0 && y == 0 )
        return 1;

      if( x-1 >= 0 && v[x-1][y] == 0 )
      {
        v[x-1][y] = 1;
        num += dfs( x-1, y, v );
        v[x-1][y] = 0;
      }
      if( y-1 >= 0 && v[x][y-1] == 0 )
      {
        v[x][y-1] = 1;
        num += dfs( x, y-1, v );
        v[x][y-1] = 0;
      }

      return num;
    }

};


int main(int argc, char const *argv[]) {
  Solution s;
  cout<<s.uniquePaths( 2, 2);
  return 0;
}
