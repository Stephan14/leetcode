/*************************************************************************
	> File Name: q12.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  1/23 21:45:40 2017
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
class Solution {
    public:
    string intToRoman(int number) {

        int i = 0;
        int base[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1  };
        string str[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX","V", "IV", "I"  };
        string roman = "";
        //贪心算法
        while (number != 0) 
        {
            if (number >= base[i]) 
            {
                number -= base[i];
                roman += str[i];
            }
            else
                i++;
        }
        return roman; 
    }
};

int main()
{
    Solution s;
    cout << s.intToRoman(44);
    return 0;
}
