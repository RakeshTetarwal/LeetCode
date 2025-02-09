#include<iostream>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        deque<pair<int, int>> dq;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dq.push_back({0, 0});
        dist[0][0] = 0;
        vector<vector<int>> dir = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!dq.empty()){
            auto [x, y] = dq.front();
            dq.pop_front();
            for(int i=1;i<=4;i++){
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                int cost = 1;
                int dir = grid[x][y];
                if(i == dir){
                    cost = 0;
                }
                if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                    if(dist[nx][ny] > dist[x][y] + cost){
                        dist[nx][ny] = dist[x][y] + cost;
                        if(cost == 0){
                            dq.push_front({nx, ny});
                        }else{
                            dq.push_back({nx, ny});
                        }
                    }
                }
            }
        }
        return dist[n-1][m-1];

    }
};

int main(){

}