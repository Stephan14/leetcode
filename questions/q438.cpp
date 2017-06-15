/*************************************************************************
	> File Name: q438.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  6/14 15:49:18 2017
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>


using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //使用两个指针固定一个窗口，判断窗口中的字符统计的值
        //与目标字符串字符统计的值是否相同
        vector<int> result;
        int left = 0, right = 0, total = p.size();
        vector<int> charMap(256, 0);
    
        for(char ch : s)
            charMap[ch]++;

        while(right < s.size())
        {
            //每次都移动右指针，当如果字符存在于p的字符串中，降低数量total
            //如果当前字符的数量大于等于1，则存在
            if(charMap[s[right++]]-- >= 1)
                --total;
            //找打符合目标的字符串
            if(total == 0)
                result.push_back(left);
            //字符长度等于目标字符长度，则向左移动指针
            //并重置map的字符数值
            if(right - left == p.size() && charMap[left++]++ >= 0)  
                ++total;
        }

        return result;
    }

};

int main()
{

}
