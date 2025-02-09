#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void find_lps(string &s, vector<int> &lps)
    {
        lps[0] = 0;
        int len=0, j=1;
        int n = s.length();
        while(j<n){
            if(s[j] == s[len]){
                len++;
                lps[j] = len;
                j++;
            }else{
                while(len>0 && s[j] != s[len]){
                    len = lps[len-1];
                }
                if(len == 0){
                    lps[i] = 0;
                    j++;
                }
            }
        }
    }

    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        int n = words.size();
        vector<int> lps[n];
        for (int i = 0; i < n; i++)
        {
            int m = words[i].length();
            lps[i] = vector<int>(2*m+2, 0);
        }
        map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            string tmp = words[i];
            reverse(tmp.begin(0, tmp.end()));
            string tmp2 = words[i] + '$' + tmp;
            find_lps(tmp, lps[i]);
            mp[words[i]] = i;
            string kmp = words[i].substr(0, (words[i].length() - lps[i][tmp2.length()]));
        }
    }
};