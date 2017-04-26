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
        //由于整型数INT的取值范围是-2147483648～2147483647，而对-2147483648取绝对值就会超出范围，所以我们需要先转为long long型再取绝对值
        int s1 = numerator >= 0 ? 1 : -1;
        int s2 = denominator >= 0 ? 1 : -1;
        long long num = abs( (long long)numerator );
        long long den = abs( (long long)denominator );
        long long out = num / den;
        long long rem = num % den;
        unordered_map<long long, int> m;

        string res = to_string(out);

        if (s1 * s2 == -1 && (out > 0 || rem > 0)) res = "-" + res;
        if (rem == 0) 
            return res;
        res += ".";

        string s = "";
        int pos = 0;
        while (rem != 0) {
            if (m.find(rem) != m.end()) {
                s.insert(m[rem], "(");
                s += ")";
                return res + s;
            }
            m[rem] = pos;
            s += to_string((rem * 10) / den);
            rem = (rem * 10) % den;
            ++pos;
        }
        return res + s;
    }

};
