#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int splitArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));
        vector<int> presum(n + 1, 0);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            dp[i + 1][1] = sum;
            presum[i + 1] = sum;
        }
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                for (int p = 2; p <= i && p <= k && (p) <= j + 1; p++)
                {
                    dp[i][p] = min(dp[i][p], max(presum[i] - presum[j],
                                                 dp[j][p - 1]));
                }
            }
        }
        return dp[n][k];
    }
};

class SolutionBS
{
public:
    bool check(vector<int> &nums, int s, int n, int k)
    {
        int sum = 0, count = 0;
        for (int i = 0; i < n; i++)
        {
            if (sum + nums[i] > s)
            {
                if (nums[i] > s)
                {
                    return false;
                }
                count++;
                if (count > k)
                {
                    return false;
                }
                sum = nums[i];
            }
            else
            {
                sum += nums[i];
            }
        }
    }
    int splitArray(vector<int> &nums, int k)
    {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        int l = 0, r = sum;
        int ans = 0;
        while (l <= r)
        {
            int m = (l + r) >> 1;
            if (check(nums, m, n, k))
            {
                ans = m;
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return ans;
    }
};
