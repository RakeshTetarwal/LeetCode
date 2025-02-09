#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    string shortestSuperstring(vector<string> &words)
    {
        int n = words.size();
        vector<vector<string>> dp(1<<(n+1), vector<string>(n+1, ""));
        vector<vector<int>> weights(n, vector<int>(n, 0));
        calculate_weights(weights, words);
        string ans = "";
        string final_ans;
        int mask = 0;
        for (int i = 0; i < n; i++)
        {
            // cout<<words[i]<<" -> ";
            ans = words[i] + min_string(i, words, (mask | (1<<i)), dp, n, weights);
            // cout<<ans<<"\n\n";
            if(final_ans == "" || final_ans.length() > ans.length()){
                final_ans = ans;
            }
        }
        return final_ans;
    }

private:
    string min_string(int ind, vector<string> &words, int mask, vector<vector<string>> & dp, int n, vector<vector<int>> &weights)
    {
        int min_len = 10000;
        string min_str = "";
        string tmp_str;
        if(dp[mask][ind] != ""){
            return dp[mask][ind];
        }
        for (int i = 0; i < n; i++)
        {
            if (!(mask & (1<<i)))
            {
                int len = words[i].length();
                int wt = weights[ind][i];
                // cout<<words[i]<<" -> ";
                tmp_str = words[i].substr(len - wt, wt) + min_string(i, words, (mask | (1<<i)), dp, n, weights);
                // cout<<"\n";
                if (tmp_str.length() < min_str.length() || min_str == "")
                {
                    min_str = tmp_str;
                }
            }
        }
        return dp[mask][ind] = min_str;
    }

    void calculate_weights(vector<vector<int>> &weights, vector<string> &words)
    {
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    weights[i][j] = weight(words[i], words[j]);
                }
            }
        }
    }
    int weight(string &a, string &b)
    {
        int len = 0;
        int index = 0;
        int n = a.length(), m = b.length();
        while (len <= min(n, m))
        {
            if (a.substr(n - len) == b.substr(0, len))
            {
                index = len;
            }
            len++;
        }
        return m - index;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    Solution s;
    cout<<s.shortestSuperstring(words)<<"\n";
}