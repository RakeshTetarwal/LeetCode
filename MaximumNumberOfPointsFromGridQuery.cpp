#include <iostream>
#include <vector>
using namespace std;

class UnionFind
{
public:
    vector<int> parent, size, rank;
    UnionFind(int n)
    {
        parent = vector<int>(n);
        size = vector<int>(n);
        rank = vector<int>(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }
public:
    int find(int u)
    {
        if (u == parent[u])
        {
            return u;
        }
        return parent[u] = find(parent[u]);
    }
    void unionByRank(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u != v)
        {
            if (rank[u] < rank[v])
            {
                swap(u, v);
            }
            parent[v] = u;
            if (rank[u] == rank[v])
            {
                rank[u]++;
            }
        }
    }

    void unionBySize(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u != v)
        {
            if (size[u] < size[v])
            {
                swap(u, v);
            }
            parent[v] = u;
            size[u] = size[u] + size[v];
        }
    }
};

class Solution
{
public:
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries)
    {
        int n = grid.size();
        int m = grid[0].size();

        auto is_valid_point = [n, m](int x, int y)
        {
            return x >= 0 && x < n && y >= 0 && y < m;
        };
        int q = queries.size();
        vector<int> res(q, 0);
        if (n == 0)
        {
            return res;
        }
        vector<vector<int>> que(q);
        for (int i = 0; i < q; i++)
        {
            que[i] = {queries[i], i};
        }
        sort(que.begin(), que.end());
        vector<vector<int>> v;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                v.push_back({grid[i][j], i, j});
            }
        }
        sort(v.begin(), v.end());
        pair<int, int> dir[] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        

        int ind = 0;
        int k = v.size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        UnionFind UF(n * m);
        for (int i = 0; i < q; i++)
        {
            while (ind < n * m)
            {
                if (v[ind][0] < que[i][0])
                {
                    int x = v[ind][1];
                    int y = v[ind][2];
                    vis[x][y] = 1;
                    for (auto d : dir)
                    {
                        int new_x = x + d.first;
                        int new_y = y + d.second;
                        if (is_valid_point(new_x, new_y) && vis[new_x][new_y])
                        {
                            UF.unionBySize(n*x + y, n*new_x + y);
                        }
                    }
                }
                ind++;
            }
            res[que[i][1]] = (vis[0][0] ? UF.size[0] : 0);
        }
        return res;
    }

};

int main()
{

}