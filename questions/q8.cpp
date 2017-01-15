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

        long long cur=0;
        int num=0,i=0;
        int flag1=0,flag2=0;

        while(str[i]!='\0' && str[i]==' ') i++;//开头空格舍弃

        if(str[i]=='-') flag1++,i++;
        else if(str[i]=='+') flag2++,i++;

        for(; str[i]!='\0'; i++)
        {
            if(str[i]>='0' && str[i]<='9')
            {
                if(flag1==2)
                {
                    cur=cur*10-(str[i]-'0');//这里是减法，因为cur符号是负号了
                    if(cur<INT_MIN) return INT_MIN;

                }
                else if(flag1==1) cur=-str[i]+'0',flag1++;//将负数的符号记录到cur里
                else
                {
                    cur=cur*10+(str[i]-'0');
                    if(cur>INT_MAX) return INT_MAX;
                }
            }
            else break;
        }

        num=(int)cur;
        return num;
    }

};

int main()
{
    Solution s;
    cout << s.myAtoi("  +-0 123");
    return 0;
}
