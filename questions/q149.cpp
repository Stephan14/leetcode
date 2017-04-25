/*************************************************************************
       > File Name: q149.cpp
       > Author:
       > Mail:
       > Created Time: 二  4/25 10:24:57 2017
************************************************************************/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
/**
 * Definition for a point.
 */
struct Point {
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
  int maxPoints(vector<Point> &points) {
    if (points.size() < 3)
      return points.size();
    int result = 0;

    for (int i = 0; i < points.size(); i++) {
      int samplePoint = 1;
      unordered_map<double, int> slopesMap; //存储斜率以及出现的次数
      for (int j = i + 1; j < points.size(); j++) {
        if (points[i].x == points[j].x && points[j].y == points[i].y)
          samplePoint++;
        else if (points[i].x == points[j].x)
          slopesMap[INT_MAX]++;
        else {
          double slopes =
              (points[i].y - points[j].y) / (points[i].x - points[j].x);
          slopesMap[slopes]++;
        }
      }
      //遍历map找出出现频率最高的斜率
      int maxTimes = 0;
      for (auto it = slopesMap.begin(); it != slopesMap.end(); it++)
        maxTimes = max(maxTimes, it->second);

      result = max(result, maxTimes + samplePoint);
    }

    return result;
  }
};
