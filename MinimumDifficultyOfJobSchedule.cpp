#include <iostream>
using namespace std;

class Solution
{
public:
    int minDifficulty(vector<int> &nums, int d)
    {
        int n = nums.size();
        if (n < d)
        {
            return -1;
        }
        vector<vector<int>> dp(n + 1, vector<int>(d + 1, INT_MAX));
        vector<int> post_max(n + 1, 0);
        post_max[n] = nums[n - 1];
        for (int i = n - 1; i > 0; i--)
        {
            post_max[i] = max(nums[i - 1], post_max[i + 1]);
        }
        dp[0][1] = 0;
        for (int i = 0; i < n; i++)
        {
            dp[i + 1][1] = max(nums[i], dp[i][1]);
        }
        for (int i = 1; i <= n; i++)
        {
        }

        for (int i = 2; i <= n; i++)
        {
            int mx = nums[n-1];
            for (int j = n - 1; j > n - i; j--)
            {
                for (int k = 2; k <= d && k <= i - (n-j) && k <= i; k++)
                {
                    dp[i][k] = min(dp[j][k - 1] + mx, dp[i][k]);
                }
                mx = max(mx, nums[j]);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= d && j <= i; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
        return dp[n][d];
    }
};

int main()
{
}