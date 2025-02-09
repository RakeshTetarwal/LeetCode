#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> leftmostBuildingQueries(vector<int> &hs,
                                        vector<vector<int>> &qs)
    {
        int m = qs.size();
        int n = hs.size();
        vector<int> ans(m, -1);
        vector<vector<pair<int, int>>> deferred_queries(n);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>()> pq;
        for (int i = 0; i < m; i++)
        {
            int x = qs[i][0];
            int y = qs[i][1];
            if (x > y)
                swap(x, y);
            if (x == y || hs[y] > hs[x])
                ans[i] = y;
            else
            {
                // Need to do something here.
                deferred_queries[y].push_back({hs[x], i});
            }
        }

        int j = n - 1;
        for (int i = 0; i < n; i++)
        {
            for(auto q: deferred_queries[i])pq.push(q);
            while(!pq.empty() && pq.top().first < hs[i]){
                ans[pq.top().second] = i;
                pq.pop();
            }
        }
        return ans;
    }
};

int main()
{
}