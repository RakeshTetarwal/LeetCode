#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution1
{
public:
    unordered_map<string, int> memo;
    int profit(vector<int> &prices, int ind, int isBuy, int total_transactions)
    {
        if (ind == prices.size() || total_transactions == 2)
        {
            return 0;
        }
        string s = to_string(ind) + to_string(isBuy) + to_string(total_transactions);
        if (memo.find(s) != memo.end())
        {
            return memo[s];
        }
        int a, b;
        if (isBuy)
        {
            a = profit(prices, ind + 1, !isBuy, total_transactions) - prices[ind];
            b = profit(prices, ind + 1, isBuy, total_transactions);
        }
        else
        {
            a = profit(prices, ind + 1, !isBuy, total_transactions + 1) + prices[ind];
            b = profit(prices, ind + 1, isBuy, total_transactions);
        }
        return memo[s] = max(a, b);
    }
    int maxProfit(vector<int> &prices)
    {
        return profit(prices, 0, 1, 0);
    }
};

class Solution3
{
public:
    unordered_map<string, int> memo;
    int profit(vector<int> &prices, int ind, int isBuy, int total_transactions, vector<vector<vector<int>>> &dp)
    {
        if (ind == prices.size() || total_transactions == 2)
        {
            return 0;
        }
        int memo = dp[ind][isBuy][total_transactions];
        if (memo != -1)
        {
            return memo;
        }
        int a, b;
        if (isBuy)
        {
            a = profit(prices, ind + 1, !isBuy, total_transactions, dp) - prices[ind];
            b = profit(prices, ind + 1, isBuy, total_transactions, dp);
        }
        else
        {
            a = profit(prices, ind + 1, !isBuy, total_transactions + 1, dp) + prices[ind];
            b = profit(prices, ind + 1, isBuy, total_transactions, dp);
        }
        return dp[ind][isBuy][total_transactions] = max(a, b);
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return profit(prices, 0, 1, 0, dp);
    }
};

class Solution2
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> left_profit(n, 0);
        int left_min = prices[0];
        for (int i = 0; i < n; i++)
        {
            left_profit[i] = max(prices[i] - left_min, 0);
            left_min = min(left_min, prices[i]);
        }
        vector<int> right_profit(n, 0);
        int right_max = prices[n - 1];
        for (int i = n - 1; i >= 0; i--)
        {
            right_profit[i] = max(0, right_max - prices[i]);
            right_max = max(right_max, prices[i]);
        }
        vector<int> pre_max(n, 0), post_max(n, 0);
        for (int i = 1; i < n; i++)
        {
            pre_max[i] = max(pre_max[i - 1], left_profit[i]);
            post_max[n - i - 1] = max(post_max[n - i], right_profit[n - i - 1]);
        }
        int ans = max(0, post_max[0]);
        for (int i = 0; i < n - 1; i++)
        {
            ans = max(ans, pre_max[i] + post_max[i + 1]);
        }
        return ans;
    }
};

class Solution4
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int isBuy = 0; isBuy <= 1; isBuy++)
            {
                for (int transaction = 1; transaction >= 0; transaction--)
                {
                    if (isBuy)
                    {
                        dp[ind][isBuy][transaction] = max(dp[ind + 1][isBuy][transaction], dp[ind + 1][!isBuy][transaction] - prices[ind]);
                    }
                    else
                    {
                        dp[ind][isBuy][transaction] = max(dp[ind + 1][!isBuy][transaction + 1] + prices[ind], dp[ind + 1][isBuy][transaction]);
                    }
                }
            }
        }
        return dp[0][1][0];
    }
};

class Solution5
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(2, vector<int>(3, 0)));
        int iter = 0;
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int isBuy = 0; isBuy <= 1; isBuy++)
            {
                for (int transaction = 1; transaction >= 0; transaction--)
                {
                    if (isBuy)
                    {
                        dp[0][isBuy][transaction] = max(dp[1][isBuy][transaction], dp[1][!isBuy][transaction] - prices[ind]);
                    }
                    else
                    {
                        dp[0][isBuy][transaction] = max(dp[1][!isBuy][transaction + 1] + prices[ind], dp[1][isBuy][transaction]);
                    }
                }
            }
            dp[1] = dp[0];
        }
        return dp[0][1][0];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n = 1 + random() % 10;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++)
        {
            v[i] = random() % 50;
            cout << v[i] << " ";
        }

        Solution1 s1;
        Solution2 s2;
        Solution3 s3;
        Solution4 s4;
        Solution5 s5;

        cout << "\nProfit1: " << s1.maxProfit(v) << "\n";
        cout << "Profit2: " << s2.maxProfit(v) << "\n";
        cout << "Profit3: " << s3.maxProfit(v) << "\n";
        cout << "Profit4: " << s4.maxProfit(v) << "\n";
        cout << "Profit5: " << s5.maxProfit(v) << "\n\n";
    }
}