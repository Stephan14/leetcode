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
      int index = 0, length = 0;

      for( vector<int>::iterator it = nums.begin(); it != nums.end(); it++ )
      {
        sprintf( temp, "%d", *it );
        sortArray.push_back(temp);
      }
      sort(sortArray.begin() , sortArray.end(), sortByWay );
      for( index = sortArray.size()-1; index >= 0; index-- )
      {
        //cout<< sortArray[ index ]<<endl;
        result.append( sortArray[ index ] );
      }
      return result;
    }

    static bool sortByWay( const string& num1, const string& num2 )
    {
      return num1 < num2;
    }

};

int main(int argc, char const *argv[]) {
  Solution solution;
  vector<int> v;
  v.push_back(121);
  v.push_back(12);
  

  cout << solution.largestNumber(v);

  return 0;
}
