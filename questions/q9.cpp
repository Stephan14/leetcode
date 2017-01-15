/*************************************************************************
	> File Name: q9.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  1/15 12:57:32 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
    public:
    bool isPalindrome(int x) {
        
        if(x < 0)
            return false;
        
        int len = 1;
        int tempx = x;
        //计算数字长度
        while(tempx / 10 > 0)
        {
            len *= 10;
            tempx /= 10;    
        }
        while(x != 0)
        {
            int right = x % 10;
            int left = x / len;

            if(right != left)
                return false;

            x = (x % len) / 10;
            len /= 100;
        }

        return true;
    }

};

int main( int argc, char *argv[])
{
    Solution s;
    cout << s.isPalindrome( 124  ) << endl;
    return 0;
}
