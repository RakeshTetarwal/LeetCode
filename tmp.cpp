#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define V 4
int travllingSalesmanProblem(int graph[][V], int s)
{
    vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);
 
    int min_path = INT_MAX;
    do {
        int current_pathweight = 0;
        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
 
        // update minimum
        min_path = min(min_path, current_pathweight);
 
    } while (
        next_permutation(vertex.begin(), vertex.end()));
 
    return min_path;
}
int main()
{
    // int graph[][V] = { { 0, 10, 15, 20 },
    //                    { 10, 0, 35, 25 },
    //                    { 15, 35, 0, 30 },
    //                    { 20, 25, 30, 0 } };
    // int s = 0;
    // for(;s<4;s++){
    // cout << travllingSalesmanProblem(graph, s) << endl;
    // }
    string tmp;
    cout<<tmp.back()<<"\n";
    return 0;
}