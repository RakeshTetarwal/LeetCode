#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int dfs(int i, int curr_len, vector<int> &edges, vector<int> &vis1, vector<int> &vis2)
    {
        if (edges[i] == -1)
        {
            vis1[i] = 1;
            return -1;
        }
        if(vis1[i]){
            return -1;
        }
        if(vis2[i]){
            return curr_len - vis2[i] + 1;
        }
        vis2[i] = curr_len;
        int ans = dfs(edges[i], curr_len + 1, edges, vis1, vis2);
        vis2[i] = 0;
        return ans;
    }
    int longestCycle(vector<int> &edges)
    {
        int n = edges.size();
        vector<int> vis1(n, 0), vis2(n, 0);
        int ans = -1;
        int curr_len = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis1[i])
            {
                curr_len = 1;
                vis2[i] = 1;
                ans = max(ans, dfs(i, curr_len, edges, vis1, vis2));
            }
        }
        return ans;
    }
};

int main()
{
}
