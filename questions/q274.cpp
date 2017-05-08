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
        
        int len = citations.size();
        vector<int> refTime(len+1, 0);//记录被引用次数为i的文章的数量
        int total = 0;
        //类似于计数排序的思想
        for(int i = 0; i < len; i++)
            if(citations[i] >= len)
                refTime[len]++;
            else
                refTime[citations[i]]++;
                
        for(int i = len; i >= 0; i--)
        {
            total += refTime[i];
            if(total >= i) return i;
        } 

        return 0;
    }
};
