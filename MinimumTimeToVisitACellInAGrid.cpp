#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution {
public:
    int n, m;
    int ans = INT_MAX;
    pair<int, int> d[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    bool isvalid(int i, int j){
        return i>=0 && i<n && j>=0 && j<m;
    }


    void dfs(int i, int j, int time, vector<vector<int>>& grid){
        if(grid[i][j] > time){
            return;
        }
        if(i==n-1 && j== m-1){
            ans = min(ans, time);
            return;
        }
        cout<<i<<" "<<j<<" "<<time<<"\n";
        for(auto [di, dj]: d){
            int i_new = i+di;
            int j_new = j+dj;
            if(!isvalid(i_new, j_new)){
                continue;
            }
            dfs(i_new, j_new, time+1, grid);
        }

    }

    int minimumTime(vector<vector<int>>& grid) {
        n = grid.size(), m=grid[0].size();
        dfs(0, 0, 0, grid);
        return ans;
    }
};

int main(){

}