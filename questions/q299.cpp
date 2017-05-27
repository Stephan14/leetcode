/*************************************************************************
	> File Name: q299.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  5/ 9 11:12:08 2017
 ************************************************************************/

#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int index = 0;
        int bull = 0, cow = 0;
        int strExist[256] = {0};//记录某一字符出现的次数

        while(index < secret.size())
        {
            if(secret[index] == guess[index])
                bull++;
            else 
            {
                //对同一个哈希表进行操作
                if(strExist[secret[index]]++ < 0)
                    cow++;
                if(strExist[guess[index]]-- > 0)
                    cow++;
            }
            index++;
        }

        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};

int main()
{
    string str1 = "1807";
    string str2 = "7810";
    Solution s;
    cout << s.getHint(str1, str2);
    return 0;
}
