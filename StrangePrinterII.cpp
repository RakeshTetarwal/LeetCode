#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, int> pii;
class Solution
{
public:
    int n, m;
    bool is_overlapping(pii p1, pii p2, pii q1, pii q2)
    {
        // Check if one rectangle is completely to the left or right of the other
        if (p2.first < q1.first || q2.first < p1.first)
            return false;

        // Check if one rectangle is completely above or below the other
        if (p2.second < q1.second || q2.second < p1.second)
            return false;

        // Otherwise, they overlap
        return true;
    }
    bool isPrintable(vector<vector<int>> &targetGrid)
    {
        map<int, pair<int, int>> mn, mx;
        n = targetGrid.size();
        m = targetGrid[0].size();
        vector<int> vis(70, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int curr = targetGrid[i][j];
                if (vis[curr])
                {
                    continue;
                }
                int count = 0;
                vis[curr] = 1;
                int mn_x = n, mn_y = m, mx_x = -1, mx_y = -1;
                for (int in = 0; in < n; in++)
                {
                    for (int jm = 0; jm < m; jm++)
                    {
                        if (targetGrid[in][jm] == curr)
                        {
                            mn_x = min(mn_x, in);
                            mn_y = min(mn_y, jm);
                            mx_x = max(mx_x, in);
                            mx_y = max(mx_y, jm);
                            count++;
                        }
                    }
                }
                vis[curr] = count;
                mn[curr] = make_pair(mn_x, mn_y);
                mx[curr] = make_pair(mx_x, mx_y);
            }
        }
        // cout<<n<<" "<<m<<"\n\n";
        // for(auto x: mn){
        //     int key = x.first;
        //     cout<<key<<"\n";

        //     cout<<mn[key].first<<" "<<mn[key].second<<"\n";
        //     cout<<mx[key].first<<" "<<mx[key].second<<"\n\n";
        // }

        vector<int> indeg(70, 0);
        vector<int> graph[70];
        for (int i = 0; i < vis.size(); i++)
        {
            if (vis[i])
            {
                for (int j = i + 1; j < vis.size(); j++)
                {
                    if (vis[j])
                    {
                        if (is_overlapping(mn[i], mx[i], mn[j], mx[j]))
                        {
                            graph[i].push_back(j);
                            graph[j].push_back(i);
                            indeg[i]++;
                            indeg[j]++;
                        }
                    }
                }
            }
        }
        queue<int> q;
        for (int i = 0; i < vis.size(); i++)
        {
            if (vis[i])
            {
                int mn_x = mn[i].first, mx_x = mx[i].first;
                int mn_y = mn[i].second, mx_y = mx[i].second;
                int count = vis[i];

                if (count == (mx_x - mn_x + 1) * (mx_y - mn_y + 1))
                {
                    q.push(i);
                }
            }
        }

        vector<int> vis_new(70, 0);
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            vis_new[curr] = 1;
            int mn_x = mn[curr].first, mn_y = mn[curr].second;
            int mx_x = mx[curr].first, mx_y = mx[curr].second;
            for (int i = mn_x; i <= mx_x; i++)
            {
                for (int j = mn_y; j <= mx_y; j++)
                {
                    targetGrid[i][j] = -1;
                }
            }

            for (auto j : graph[curr])
            {
                if (vis_new[j])
                {
                    continue;
                }
                int mn_x = mn[j].first, mn_y = mn[j].second;
                int mx_x = mx[j].first, mx_y = mx[j].second;
                int cnt = 0;
                for (int in = mn_x; in <= mx_x; in++)
                {
                    for (int jm = mn_y; jm <= mx_y; jm++)
                    {
                        if (targetGrid[in][jm] == j || targetGrid[in][jm] == -1)
                        {
                            cnt++;
                        }
                    }
                }
                if (cnt == (mx_x - mn_x + 1) * (mx_y - mn_y + 1))
                {
                    q.push(j);
                }
            }
        }
        for (int i = 0; i < vis.size(); i++)
        {
            if (bool(vis[i]) != bool(vis_new[i]))
            {
                return false;
            }
        }
        return true;
    }
};

class Solution2
{
public:
    int n, m;

    bool dfs(int curr, vector<int>& vis, vector<vector<int>> &grid, vector<vector<int>> &arr){
        vis[curr] = 2;
        int t = arr[curr][0], b = arr[curr][2];
        int l = arr[curr][1], r = arr[curr][3];
        for(int i=t; i<=b;i++){
            for(int j=l; j<=r;j++){
                int next = grid[i][j];
                if(curr == next){
                    continue;
                }
                if(vis[next] == 2){
                    return false;
                }
                int ans = 1;
                if(vis[next] == 1){
                    ans = dfs(next, vis, grid, arr);
                }
                if(ans == 0){
                    return false;
                }
            }
        }
        vis[curr] = 3;
        return true;
    }


    bool isPrintable(vector<vector<int>> &targetGrid)
    {
        n = targetGrid.size();
        m = targetGrid[0].size();
        vector<vector<int>> arr(61, vector<int>(4));
        vector<int> vis(61, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int curr = arr[i][j];
                if(!vis[i]){
                    arr[curr][0] = arr[curr][2] = i;
                    arr[curr][1] = arr[curr][3] = j;
                    vis[i] = 1;
                }else{
                    arr[curr][0] = min(arr[curr][0], i);
                    arr[curr][1] = min(arr[curr][1], j);

                    arr[curr][2] = max(arr[curr][2], i);
                    arr[curr][3] = max(arr[curr][3], j);
                }
            }
        }
        int ans = 1;
        for(int i=0;i<60;i++){
            if(vis[i] && vis[i] != 3){
                ans = ans && dfs(i, vis, targetGrid, arr);
                if(ans == 0){
                    return false;
                }
            }
        }
        return true;

    }
};

int main()
{
}