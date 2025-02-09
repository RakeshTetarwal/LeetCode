#include<iostream>
#include<vector>
#include<map>
using namespace std;



class Solution {
public:


    void find_max_node(int curr, int& max_dep, int& max_node, int curr_depth, vector<vector<int>>& graph, int par=-1){
        if(curr_depth > max_dep){
            max_dep = curr_depth;
            max_node = curr;
        }
        for(auto next: graph[curr]){
            if(next != par){
                find_max_node(next, max_dep, max_node, curr_depth + 1, graph, curr);
            }
        }
    }


    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<vector<int>> graph1(n), graph2(m);
        for(auto& e:edges1){
            graph1[e[0]].push_back(e[1]);
            graph1[e[1]].push_back(e[0]);
        }
        for(auto& e:edges2){
            graph2[e[0]].push_back(e[1]);
            graph2[e[1]].push_back(e[0]);
        }
        int max_dep1 = 0, mx_node1 = 0;
        int max_dep2 = 0, mx_node2 = 0;
        find_max_node(0, max_dep1, mx_node1, 0, graph1);
        find_max_node(0, max_dep2, mx_node2, 0, graph2);
        int d_end1 = 0, d_end2 = 0, d_max_1 = 0, d_max_2 = 0;
        find_max_node(mx_node1, d_max_1, d_end1, 0, graph1);
        find_max_node(mx_node2, d_max_2, d_end2, 0, graph2);
        return (d_max_1+1)>>1 + (d_max_2 + 1)>>1;
    }
};

int main(){

}
