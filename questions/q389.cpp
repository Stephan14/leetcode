/*************************************************************************
	> File Name: q389.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  6/ 6 22:10:26 2017
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
        int strTimes[128] = {0};
        for(auto &it : s)
            strTimes[it]++;
        for(auto &it : t)
            if(--strTimes[it] < 0)
                return it;
        return ' ';
    }
};

int main()
{
    return 0;
}
