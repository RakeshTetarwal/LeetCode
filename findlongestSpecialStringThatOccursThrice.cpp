#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:


    int maximumLength(string s)
    {
        map<char, map<int, int>> mp;
        char ch = '\0';
        int freq = 0;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ch)
            {
                freq++;
            }
            else
            {
                for (int j = 1; j <= freq; j++)
                {
                    mp[ch][j] += (freq + 1 - j);
                }
                freq = 1;
                ch = s[i];
            }
        }
        for (int j = 1; j <= freq; j++)
        {
            mp[ch][j] += (freq + 1 - j);
        }
        int ans = -1;
        for (auto &[ch, freq_mp] : mp)
        {
            for (auto &[i, num] : freq_mp)
            {
                if(num >= 3){
                    ans = max(ans, i);
                }
            }
        }
        return ans;
    }
};

int main()
{
}