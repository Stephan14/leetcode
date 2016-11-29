#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        string convert(string s, int numRows) {
            string result;
            vector< vector< char > > array( numRows, vector<char>() );
            
            if( numRows == 1 ) return s;

            for( int index = 0; index < s.size(); index++ )
            {
                int temp = index % ( 2 * numRows -2 );

                if( temp < numRows )
                    array[ temp ].push_back( s[index] );
                else
                    array[ numRows -  (temp % numRows + 2) ].push_back( s[index] );
            }

            for( int row = 0; row < array.size(); row++ )
                for( int column = 0; column <  array[ row ].size(); column++ )
                    result += array[ row ][ column ];
            return result;
        }

};


int main( int argc, char *argv[] )
{
    Solution so;
    string s("PAYPALISHIRING");
    cout <<  so.convert( s, 3 );
    return 0;
}
