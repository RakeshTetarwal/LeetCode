#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> createAdj(vector<vector<int>>& edges){
        vector<vector<int>> t(edges.size()+1);
        for(auto e:edges){
            t[e[0]].push_back(e[1]);
            t[e[1]].push_back(e[0]);
        }
        return t;
    }
    int dfs(int curr, vector<vector<int>>& adj, int r, int par = -1){
        if(r==0){
            return 1;
        }
        int ans = 1;
        for(auto nxt:adj[curr]){
            if(nxt != par)
                ans += dfs(nxt, adj, r-1, curr);
        }
        return ans;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        auto adj1 = createAdj(edges1), adj2 = createAdj(edges2);
        int a1 = 0;
        for(int i = 0;i<=edges2.size();i++){
            a1 = max(a1, dfs(i, adj2, k-1));
        }
        vector<int> ans(edges1.size()+1, 0);
        for(int i=0;i<=edges1.size();i++){
            ans[i] = a1 + dfs(i, adj2, k);
        }
        return ans;


    }
};