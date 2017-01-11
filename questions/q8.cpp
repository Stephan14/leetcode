/*************************************************************************
	> File Name: q8.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  1/11 23:03:19 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
    public:
    int myAtoi(string str) {
       
        int resultToResult = 0;
        int flag = 1;
        bool is = false;

        if(str.size() == 0)
            return 0;

        for(size_t index = 0; index < str.size(); index++)
        {
            if(str[index] == '-' && resultToResult == 0 )
            {
                flag = -1;
                is = true;
                continue;
            }
            else if(str[index] == '+' && resultToResult == 0)
            {
                is = true;
                continue;
            }
            else if((str[index] == '+' || str[index] == '-') && is )//+-号同时出现
            {
                resultToResult = 0;
                break;
            }
            else if((str[index] == ' ' || str[index] == '0') && resultToResult == 0) //前几位为空格或者为0
                continue;

             resultToResult = resultToResult * 10 + str[index] - '0';  
        }
           
        return flag * resultToResult;
    }

};

int main()
{
    Solution s;
    cout << s.myAtoi("-321");
    return 0;
}
