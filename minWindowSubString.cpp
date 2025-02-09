#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int i = 0, j = 0;
        int n = s.length();
        int count = 0;
        int ans = INT_MAX;
        map<char, int> mp1, mp2;
        for (auto t1 : t)
        {
            mp1[t1]++;
        }
        while (j < n)
        {
            mp2[s[j]]++;
            j++;
            if (mp1.count(s[j]) && mp1[s[j]] == mp2[s[j]])
            {
                count++;
            }
            if (count == mp1.size())
            {
                while (mp1.count(s[i]) && mp1[s[i]] < mp2[s[i]])
                {
                    i++;
                }
                ans = min(ans, j - i + 1);
            }
        }
        return ans;
    }
};

int main()
{
}