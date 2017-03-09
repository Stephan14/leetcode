/*************************************************************************
	> File Name: q56.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  3/ 9 22:13:38 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/**
 * Definition for an interval.
 */
  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
class Solution {
public:
    static  bool comp(const Interval &a, const Interval &b )
    {
       return a.start < b.start;  
    }

    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if(intervals.empty())
            return result;

        sort(intervals.begin(), intervals.end(), comp); 
        result.push_back(intervals[0]);
        
        for(int index = 1; index < intervals.size(); index++)
        {
            if(result.back().end >= intervals[index].start) 
                result.back().end = max(result.back().end, intervals[index].end);//注意取最大值
            else
                result.push_back(intervals[index]);
        }

        return result;
    }
};

int main()
{
    return 0;
}

