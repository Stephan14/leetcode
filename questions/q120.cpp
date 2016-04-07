#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;


class Solution {
public:
    int minimumTotal(vector< vector<int> >& triangle) {
      int level = 0, column = 0;
      int mininumtotal = INT_MAX;
      vector< vector<int> > total;
      total.push_back( vector<int>(1, triangle[ level ][ column ]) );

      while( ++level < triangle.size() )
      {
        vector<int> temp( triangle.at(level).size(), 0);

        for( column = 0; column < triangle.at(level).size(); column++ )
           if( column == 0 )
           {
            temp[ column ] = total[ level-1 ][ column ] + triangle[ level ][ column ];
            cout<<temp[column]<<" ";
          }
           else if( column == (triangle.at(level).size() - 1) )
           {
            temp[ column ] = total[ level-1 ][ column-1 ] + triangle[ level ][ column ];
            cout<<temp[column]<<" ";
           }
           else
           {
             if( total[ level-1 ][ column ] > total[ level-1 ][ column-1 ])
                temp[ column ] = total[ level-1 ][ column -1] + triangle[ level ][ column ];
              else
                temp[ column ] = total[ level-1 ][ column ] + triangle[ level ][ column ];
                cout<<temp[column]<<" ";
           }
           cout<<endl;
        total.push_back( temp );
      }


      for( vector<int>::iterator it = total.at( level-1 ).begin(); it != total.at( level-1 ).end(); ++it )
      {
        mininumtotal = mininumtotal < *it ? mininumtotal : *it;
        cout<<*it<<endl;
      }
      return mininumtotal;
    }

};

int main(int argc, char const *argv[]) {
  //vector的初始化方法
  vector< vector< int > > v( 4, vector<int>( 4, 0 ) );
  v[0][0] = 2;
  v[1][0] = 3;
  v[1][1] = 4;
  v[2][0] = 6;
  v[2][1] = 5;
  v[2][2] = 7;
  v[3][0] = 4;
  v[3][1] = 1;
  v[3][2] = 8;
  v[3][3] = 3;

  Solution s;
  cout<<s.minimumTotal( v );
  return 0;
}
