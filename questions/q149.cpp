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
            unordered_map<pair<int, int>, int> slopesMap; //存储斜率以及出现的次数

            for (int j = i + 1; j < points.size(); j++) {
                if (points[i].x == points[j].x && points[j].y == points[i].y)
                samplePoint++;
                int dy = points[i].y - points[j].y;
                int dx = points[i].x - points[j].x;
                int d = gcd(dy, dx);
                slopesMap[{dy / d, dx / d}]++;
            }
            //遍历map找出出现频率最高的斜率
            int result = max(result, samplePoint);
            for (auto it = slopesMap.begin(); it != slopesMap.end(); it++)
            result = max(result, it->second + samplePoint);
        }

        return result;
    }

    private:
    int gcd(int a, int b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }
};
