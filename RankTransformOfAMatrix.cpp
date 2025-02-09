#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define pii pair<int, int>
#define ss second
#define ff first

class Union
{
    vector<vector<pii>> par;
    vector<vector<int>> size;

public:
    Union(int n, int m)
    {
        par = vector<vector<pii>>(n, vector<pii>(m));
        size = vector<vector<int>>(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                par[i][j] = {i, j};
                size[i][j] = 1;
            }
        }
    }
    pii parent(pii p)
    {
        if (p == par[p.ff][p.ss])
        {
            return p;
        }
        return par[p.ff][p.ss] = parent(par[p.ff][p.ss]);
    }
    void make_union(pii a, pii b)
    {
        pii pa = parent(a), pb = parent(b);
        if (pa != pb)
        {
            if (size[pa.ff][pa.ss] < size[pb.first][pb.second])
            {
                swap(pa, pb);
            }
            parent[pb.first][pb.second] = pa;
        }
    }
};

class Solution
{
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> rank(n, vector<int>(m, 1));
        vector<map<int, pii>> row, col;
        Union dsu(n, m);
        vector<vector<int>> v;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int val = matrix[i][j];
                v.push_back({val, i, j});
                if (row[i].count(val))
                {
                    dsu.make_union({i, j}, row[i][val]);
                }
                if (col[j].count(val))
                {
                    dsu.make_union({i, j}, col[j][val]);
                }
                row[i][val] = col[j][val] = { i,
                                              j }
            }
        }
        sort(v.begin(), v.end());
        vector<pii> r(n, {-1, -1}), c(m, {-1, -1});
        for (auto &x : v)
        {
            int val=x[0], i=x[1], j=x[2];
            if(r[i].first != -1){
                auto[x, y] = r[i];
                rank[i][j] = max(rank[i][i], rank[x][y] + val != matrix[x][y]);
            }
            if(c[j].first != -1){
                auto[x, y] = c[j];
                rank[i][j] = max(rank[i][i], rank[x][y] + val != matrix[x][y]);
            }
            auto[x, y] = dsu.parent(i, j);
            rank[i][j] = max(rank[x][y], rank[i][j]);
            rank[x][y] = rank[i][j];
        }
        return rank;
    }
};
