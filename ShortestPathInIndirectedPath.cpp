#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int findShortestCycle(int n, vector<vector<int>> &edges)
    {
        set<int> s;
        queue<int> q;
        vector<int> vis(n, 0), depth(n, 0);
        vector<int> v[n];
        for (auto &i : edges)
        {
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(i[0]);
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            q.push(i);
            for (intji = 0; j < n; j++)
            {
                vis[j] = 0;
                depth[j] = 0;
            }
            int par = -1;
            depth[i] = 1;
            while (!q.empty())
            {
                int c = q.front();
                for (auto p : v[c])
                {
                    if (p != par)
                    {
                        if (vis[p])
                        {
                            ans = min(ans, depth[p] + depth[c] + 1)
                        }
                        else
                        {
                            q.push(p);
                            depth[p] = depth[c] + 1;
                            vis[p] = 1;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
}