#include <iostream>
#include <vector>
#include<list>
#include <map>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<vector<int>> validArrangement(vector<vector<int>> &pairs)
    {
        map<int, list<int>> graph;
        map<int,int> deg;
        int n=pairs.size();
        for(int i=0;i<n;i++){
            graph[pairs[i][0]].push_back(pairs[i][1]);
            deg[pairs[i][0]]++;
            deg[pairs[i][1]]--;
        }
        int start = pairs[0][0];
        for(auto& [node, degree]: deg){
            if(degree == 1){
                start = node;
                break;
            }
        }
        vector<vector<int>> ans;
        function<void(int)> dfs = [&](int curr){
            list<int>& neigh = graph[curr];
            while(!neigh.empty()){
                int next = neigh.front();
                neigh.pop_front();
                dfs(next);
                ans.emplace_back(curr, next);
            }
        };
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
}