/*************************************************************************
	> File Name: q166.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  4/26 10:59:45 2017
 ************************************************************************/

#include<iostream>
#include<string>
#include<unordered_map>


using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
    
        string strToReturn;
        
        if(numerator == 0)
            return "0";
        //判断正负号
        if(numerator < 0 ^ denominator < 0) //使用异或运算符,条件都成立或者都失败，返回false 
            strToReturn += "-";

        numerator = abs(numerator);
        denominator = abs(denominator);

        strToReturn += to_string(numerator / denominator);//不用判断商是否为0

        if(numerator % denominator == 0)
            return strToReturn;
        else 
            strToReturn += ".";
        
        unordered_map<int, int> remainderMap;
        for(int remainder = numerator % denominator; remainder; remainder %= denominator)
        {
            if(remainderMap.count(remainder) > 0) 
            {
                strToReturn.insert(remainderMap[remainder], 1, '(');
                strToReturn += ')';
                break;
            }

            remainderMap[remainder] = strToReturn.size();

            remainder *= 10;//向上一位借10

            strToReturn += to_string(remainder / denominator);
        }

        return strToReturn;
        
    }

};
