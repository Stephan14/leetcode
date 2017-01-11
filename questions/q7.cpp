/*************************************************************************
	> File Name: q7.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  1/10 23:16:27 2017
 ************************************************************************/

#include<iostream>
#include<sstream>
#include<string>

using namespace std;
class Solution
{
    public:
//    string num2str(double num)
//    {
//        stringstream ss;
//        ss << num;
//        return ss.str();
//    }
//
//    double str2num(string str)
//    {
//        double num;
//        stringstream ss(str);
//        ss >> num;
//        return num;
//    }
    long long int f(long long int x)
    {
        long long int resultToReturn = 0;
        while( x != 0 )
        {
            long long int t = x % 10;
            x = x / 10;
            resultToReturn = resultToReturn * 10 + t; 
        }
        return resultToReturn;
    }
};

int main()
{
    Solution s;
    cout << s.f(-123) << endl;
    cout << -1/10 << endl;
    cout << -1%10 << endl;
//    cout << s.num2str(56) << endl;
//    string str("45"); 
//    cout << s.str2num(str) << endl;
    return 0;
}
