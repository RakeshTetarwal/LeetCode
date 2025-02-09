#include <iostream>
using namespace std;

class Solution
{
public:
    int find_max_sum(int n, int ind, int count, int k, vector<int>& pre_sum, vector<vector<int>> &dp)
    {
        if (count == -1)
        {
            return 0;
        }
        if (ind > n - count * k)
        {
            return 0;
        }
        if(dp[ind][count] != -1){
            return dp[ind][count];
        }
        int dont_count = find_max_sum(nums, ind+1, count, k, pre_sum, dp);
        int count = (pre_sum[ind+1+k] - pre_sum[ind]) + find_max_sum(nums, ind+k, count-1, k, pre_sum, dp);
        return dp[ind][count] = max(count, dont_count);
    }
    void find_max_path(int n, int ind, int count, int k, vector<int>& pre_sum, vector<vector<int>> &dp, vector<int>& path)
    {
        int n=
        if(count == -1){
            return;
        }
        if (ind > n - count * k)
        {
            return 0;
        }
        int dont_count = find_max_sum(n, ind+1, count, k, pre_sum, dp);
        int count = (pre_sum[ind+1+k] - pre_sum[ind]) + find_max_sum(n, ind+k, count-1, k, pre_sum, dp);
        if(count >= dont_count){
            path.push_back(ind);
            find_max_path(n, ind+k, count - 1, k, pre_sum, dp, path);
        }else{
            find_max_path(n, ind+1, count, k, pre_sum, dp, path);
        }
    }
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> path;
        vector<int> pre_sum(n+1, 0);
        vector<vector<int>> dp(n, vector<int>(3, -1));
        for(int i=0;i<n;i++){
            pre_sum[i+1] = pre_sum[i] + nums[i];
        }
        find_max_sum(n, 0, 2, k, pre_sum, dp);
        find_max_path(n, 0, 2, k, pre_sum, dp, path);
        return path;
    }
};

int main()
{
}