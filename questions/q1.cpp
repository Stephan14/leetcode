#include<iostream>
#include<vector>
#include<map>

using namespace std;
class Solution {
public:
    // vector<int> twoSum(vector<int>& nums, int target) {
    //   int right = 0;
    //   int left = 0;
    //   int flag = 1;
    //   vector<int> result ;
    //
    //   //sort( nums.begin(), nums.end(), cmp );
    //   for( ; right < nums.size() && flag ; right++ )
    //     for( left = right + 1; left < nums.size() && flag; left++ )
    //     {
    //       cout<<"nums["<<right<<"] = "<<nums[right]<<endl;
    //       cout<<"nums["<<left<<"] = "<<nums[left]<<endl;
    //       if( nums[right] + nums[left] == target )
    //       {
    //         cout<<"nums["<<right<<"] = "<<nums[right]<<endl;
    //         cout<<"nums["<<left<<"] = "<<nums[left]<<endl;
    //         result.push_back( right );
    //         result.push_back( left );
    //         flag = 0;
    //       }
    //     }
    //   return result;
    //
    // }
    // //参数一定要加const
    // static bool cmp( const int &num1, const int &num2 )
    // {
    //   return num1 < num2;
    // }

    vector<int> twoSum(vector<int>& nums, int target)
    {
      int index;
      vector<int> result;
      map<int, int> map;
      for( index = 0; index < nums.size(); index++ )
      {
        if( !map.count( nums[index] ) )
          map.insert(pair<int, int> (nums[index], index) );
        if( map.count( target - nums[index] ) )
        {
          int n = map[ target - nums[index] ];
          if( n < index)
          {
            result.push_back( n );
            result.push_back( index );
          }
        }
       }
       return result;
    }
};
int main(int argc, char const *argv[]) {
  vector<int> v;
  v.push_back(3);
  v.push_back(2);
  v.push_back(4);
  //v.push_back(15);
  int sum = 6;
  Solution s;
  vector<int> r = s.twoSum( v, sum);
  cout<<r[0]<<endl;
  cout<<r[1]<<endl;

  return 0;
}
