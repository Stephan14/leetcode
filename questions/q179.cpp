/*179. Largest Number*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

class Solution {
public:

    string largestNumber(vector<int>& nums) {
      vector<string> sortArray;
      string result;
      char temp[256];
      int index = 0, flag = 1;

      for( vector<int>::iterator it = nums.begin(); it != nums.end(); it++ )
      {
        if( *it != 0 ) flag = 0;
        sprintf( temp, "%d", *it );
        sortArray.push_back(temp);
      }

      if( flag )
      {
        result.append("0");
        return result;
      }
      sort(sortArray.begin() , sortArray.end(), sortByWay );
      for( index = sortArray.size()-1; index >= 0; index-- )
        //cout<< sortArray[ index ]<<endl;
        result.append( sortArray[ index ] );

      return result;
    }

    static bool sortByWay( const string& num1, const string& num2 )
    {
      string temp1( num1 );
      string temp2( num2 );
      temp1.append( num2 );
      temp2.append( num1 );

      return temp1 < temp2;
    }

};

int main(int argc, char const *argv[]) {
  Solution solution;
  vector<int> v;
  v.push_back(0);
  v.push_back(0);
  v.push_back(0);
  v.push_back(0);


  cout << solution.largestNumber(v);

  return 0;
}
