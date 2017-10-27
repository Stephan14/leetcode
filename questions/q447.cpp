/*************************************************************************
	> File Name: q447.cpp
	> Author: 
	> Mail: 
	> Created Time: 五 10/27 10:21:35 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int> >& points) {
        int result = 0;

        for (int i = 0; i < points.size(); ++i) {
            map<int, int> record;
            for (int j = 0; j < points.size(); ++j) {
                int a = points[i].first - points[j].first;
                int b = points[i].second - points[j].second;
                ++record[a * a + b * b];
            }
            
            for (auto it = record.begin(); it != record.end(); ++it) 
            {
                result += it->second * (it->second - 1);
            }
        }

        return result;

    }
};
