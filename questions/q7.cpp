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
    int reverse(int x) {
        const int max = 0x7fffffff;  //int最大值  
        const int min = 0x80000000;  //int最小值  
        int sum = 0;   

        while(x != 0)  
        {  
            int temp = sum * 10 + x % 10;  
            x = x / 10;  

            if ( temp / 10 != sum )   //溢出处理  
            {  
                sum = 0;
                break;
            }  
            sum = temp;
        }  
        return sum;   
    }
};

int main()
{
    Solution s;
    cout << s.reverse(1534236469) << endl;
    cout << -1/10 << endl;
    cout << -1%10 << endl;
//    cout << s.num2str(56) << endl;
//    string str("45"); 
//    cout << s.str2num(str) << endl;
    return 0;
}
