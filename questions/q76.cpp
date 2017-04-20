/*************************************************************************
	> File Name: q76.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  4/12 10:37:04 2017
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int counter = t.size(), begin = 0, end = 0, min_len = INT_MAX, head = 0;
        vector<int> map(128, 0);

        for(auto c: t) map[ c ]++;

        while(end < s.size())
        {
            if(map[ s[ end++ ] ]-- > 0) 
                counter--; 

            while(counter == 0)
            {
                if(end - begin < min_len)  
                    min_len = end - ( head = begin );
                if(map[ s[ begin++ ] ]++ == 0) 
                    counter++;  
            }
        }

        return min_len== INT_MAX ? "" : s.substr(head, min_len);
    }
};

int main()
{
    return 0;
}
