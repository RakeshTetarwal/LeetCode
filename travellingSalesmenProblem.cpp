#include <iostream>
#include <vector>
using namespace std;

int min_path(vector<vector<int>> &v, vector<int> &vis, int ind, int n, int start)
{
    int path_val = 1000000;
    for (int i = 0; i < n; i++)
    {
        if(i != ind && !vis[i]){
            vis[i] = 1;
            path_val = min(path_val, v[ind][i] + min_path(v, vis, i, n, start));
            vis[i] = 0;
        }
    }
    return path_val == 1000000?v[ind][start]: path_val;
}

int main()
{
    int n = 4;
    vector<vector<int>> v = {{0, 10, 15, 20},
                             {10, 0, 35, 25},
                             {15, 35, 0, 30},
                             {20, 25, 30, 0}};
    int ans = INT_MAX;
    vector<int> vis(n, 0);

    for (int i = 0; i < n; i++)
    {
        vis[i] = 1;
        ans = min(ans, min_path(v, vis, i, n, i));
        cout<<ans<<"\n";
        vis[i] = 0;
    }
    cout<<ans<<"\n";
}