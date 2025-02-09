#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int magnificentSets(int n, vector<vector<int>> &edges)
    {
        vector<int> v[n + 1];
        for (auto &e : edges)
        {
            int i = e[0], j = e[1];
            v[i].push_back(j);
            v[j].push_back(i);
        }
        vector<vector<int>> cc;
        vector<int> vis(n + 1, 0);
        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                q.push(i);
                vis[i] = 1;
                vector<int> c;
                while (!q.empty())
                {
                    int curr = q.front();
                    q.pop();
                    c.push_back(c);
                    for (auto j : v[i])
                    {
                        if (!vis[j])
                        {
                            q.push(j);
                            vis[j] = 1;
                        }
                    }
                }
                cc.push_back(c);
            }
        }
        vector<int> nodes_cc(cc.size(), -1), level(n + 1, 0);
        int cc_no = 0;
        for (auto &c : cc)
        {
            for (auto i : c)
            {
                for (int j = 1; j <= n; j++)
                {
                    vis[j] = 0;
                }
                q.push(i);
                vis[i] = 1;
                level[i] = 1;
                int cont = 1;
                while (!q.empty() && cont)
                {
                    int curr = q.front();
                    q.pop();
                    for (int child : v[curr])
                    {
                        if (vis[child] && level[child] == level[curr])
                        {
                            cont = 0;
                            break;
                        }
                        else if (!vis[child])
                        {
                            q.push(child);
                            level[child] = level[curr] + 1;
                            vis[child] = 1;
                        }
                    }
                }
                if(cont){
                    for(int i: c){
                        nodes_cc[cc_no] = max(nodes_cc[cc_no], level[i]);
                    }
                }else{
                    nodes_cc[cc_no] = -1;
                }
            }
            cc_no++;
        }
        int ans = 0;
        for(int i: nodes_cc){
            if(i==-1){
                return -1;
            }
            ans += i;
        }
        return ans;
    }
};

int main()
{
}