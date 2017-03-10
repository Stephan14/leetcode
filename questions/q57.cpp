/*************************************************************************
	> File Name: q57.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  3/10 22:13:10 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

/*
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
    static bool comp(const Interval &a, const Interval &b)
    {
        return a.start > b.start;
    }

    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        if(intervals.empty())
        {
            res.push_back(newInterval);
            return res;
        }
        
        sort(intervals.begin(), intervals.end(), comp);
        res.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++) 
        {
            if(res.back().end >= newInterval.start) 
            {
                res.back().end = max(res.back().end, newInterval.end);
                res.back().start = min(res.back().start, newInterval.start);
            }
            else
                res.push_back(newInterval);
        }

        return res;
    }
};

int main()
{
    return 0;
}

