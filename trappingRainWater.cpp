#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> pre_max(n, 0), post_max(n, 0);
        for (int i = 1; i < n; i++)
        {
            pre_max[i] = max(pre_max[i - 1], height[i - 1]);
            int post_index = n - i - 1;
            post_max[post_index] = max(post_max[post_index + 1], height[post_index + 1]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int bar = min(post_max[i], pre_max[i]);
            ans += max(0, bar - height[i]);
        }
        return ans;
    }
};

///// !This is wrong
/*

    4 4 4 4
    4 3 3 4
    4 4 3 4

*/

class Solution
{
public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        int n = heightMap.size();
        if (n == 0)
            return 0;
        int m = heightMap[0].size();
        vector<vector<int>> hori_pre_max(n, vector<int>(m, 0)), hori_post_max(n, vector<int>(m, 0));
        vector<vector<int>> vert_pre_max(n, vector<int>(m, 0)), vert_post_max(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                int ind = m - j - 1;
                hori_pre_max[i][j] = max(hori_pre_max[i][j - 1], heightMap[i][j - 1]);
                hori_pre_max[i][ind] = max(hori_pre_max[i][ind + 1], heightMap[i][ind + 1]);
            }
        }
        for (int j = 0; j < m; j++)
        {
            for (int i = 1; i < n; i++)
            {
                int ind = n - i - 1;
                vert_pre_max[i][j] = max(vert_pre_max[i - 1][j], heightMap[i - 1][j]);
                vert_post_max[ind][j] = max(vert_post_max[ind + 1][j], heightMap[ind + 1][j]);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int bound = min(hori_pre_max[i][j], min(hori_post_max[i][j], min(vert_pre_max[i][j], vert_post_max[i][j])));
                ans += max(0, heightMap[i][j] - bound);
            }
        }
        return ans;
    }
};

class Solution
{
public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int n = heightMap.size();
        if (n == 0)
        {
            return 0;
        }
        int m = heightMap[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                {
                    pq.push({heightMap[i][j], {i, j}});
                }
            }
        }
        int ans = 0;
        vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!pq.empty())
        {
            auto x = pq.top();
            pq.pop();
            int height = x.first;
            int i = x.second.first;
            int j = x.second.second;
            for (auto dir : d)
            {
                int d_i = i + dir.first;
                int d_j = j + dir.second;
                if (d_i >= 0 && d_j >= 0 && d_i < n && d_j < m && !vis[d_i][d_j])
                {
                    int n_height = heightMap[d_i][d_j];
                    if (n_height >= height)
                    {
                        pq.push({n_height, {d_i, d_j}});
                    }else{
                        ans += height - n_height;
                        pq.push({height, {d_i, d_j}});
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v = {4, 2, 0, 3, 2, 5};
    cout << s.trap(v) << "\n";
}