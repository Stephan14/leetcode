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
        char r=0;
        for(char c:s) r ^=c;
        for(char c:t) r ^=c;
        return r;
    }

};

int main()
{
    return 0;
}
