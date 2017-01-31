/*************************************************************************
	> File Name: q13.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  1/31 09:34:23 2017
 ************************************************************************/

#include<iostream>
#include<string>

using namespace std;

class Solution {
    public:
    int getNumber(char ch)
    {
        switch(ch)
        {
            case 'I': return 1;   
            case 'V': return 5;  
            case 'X': return 10;  
            case 'L': return 50;  
            case 'C': return 100;  
            case 'D': return 500;  
            case 'M': return 1000;  
            default: return 0;
        }
    }

    int romanToInt(string s) {

        int index = 0;
        int result = 0;
        int sub = getNumber(s[0]);
        int last = getNumber(s[0]);
        char lastch = s[0];

        for(index = 1; index < s.size(); index++)
        {
            int cur = getNumber(s[index]);
            char curch = s[index];

            if(cur == last)    
                 sub += getNumber(curch); 
            else if(cur < last)
            {
                 result += sub;
                 sub = cur; 
            }
            else
            {
                sub = cur - sub;    
            }
            lastch = curch;
            last = cur;
        }

        result += sub;
        return result;
    }

};

int main()
{
    Solution s;
    cout << s.romanToInt("XIX");
    return 0;
}
