/*************************************************************************
	> File Name: q274.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  5/ 8 09:22:45 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        sort(citations.begin(), citations.end(), greater<int>());//从高到低排序
        for(int i = 0; i < citations.size(); i++)
            if(citations[i] <= i)
                return i;

        return citations.size();
    }
};
