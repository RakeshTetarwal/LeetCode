#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pre_pq;
        int k = nums.size();
        int mn = INT_MAX, mx = INT_MIN;
        for (int i = 0; i < k; i++)
        {
            mn = min(mn, nums[i][0]);
            mx = max(mx, nums[i][0]);
            pre_pq.push({nums[i][0], i, 0});
        }
        int ans = INT_MAX;
        int ans_mx, ans_mn;
        if (ans > mx - mn)
        {
            ans_mn = mn, ans_mx = mx;
        }
        while (1)
        {
            auto x = pre_pq.top();
            mn = x[0];
            int ind = x[1];
            int m_ind = x[2];
            if(m_ind + 1 == nums[ind].size()){
                break;
            }
            mx = max(mx, nums[ind][m_ind]);
            pre_pq.push({nums[ind][m_ind], ind, m_ind+1});
            if (ans > mx - mn)
            {
                ans_mn = mn, ans_mx = mx;
            }
        }
        return {ans_mn, ans_mx};
    }
};