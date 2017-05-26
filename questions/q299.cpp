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
        int secretIndex = 0;
        int guessIndex = 0;
        int bull = 0, cow = 0;

        while(secretIndex < secret.size() && guessIndex < guess.size())
        {
            if(secret[secretIndex] == guess[guessIndex])
            {
                bull++;
                cout << "same" << secret[secretIndex] << endl;
            }
            else if(secret.find(guess[guessIndex]) != string::npos)
            {
                cow++;
                cout << "diff" << guess[guessIndex] << endl;
            }
            secretIndex++, guessIndex++;
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
