#include <iostream>
using namespace std;

// class Solution
// {
// public:
//     int maximumInvitations(vector<int> &favorite)
//     {
//         int n = favorite.size();
//         int m = favorite[0].size();
//         vector<vector<int>> reversedGraph(n);
//         for (int i = 0; i < n; i++)
//         {
//             reversedGraph[favorite[i]].push_back(i);
//         }
//         auto bfs = [&](int curr, unordered_set<int> &visited)
//         {
//             queue<pair<int, int>> q;
//             q.push({curr, 0});
//             visited.insert(curr);
//             int ans = 0;
//             while (!q.empty())
//             {
//                 auto [node, depth] = q.front();
//                 q.pop();
//                 for (auto next : reversedGraph[node])
//                 {
//                     if (visited.find(next) == visited.end())
//                     {
//                         visited.insert(next);
//                         q.push({next, depth + 1});
//                         ans = max(ans, depth + 1);
//                     }
//                 }
//             }
//             return ans;
//         };
//         int ans = 0;
//         int longestCycle = 0, twoCycleInvitations = 0;
//         vector<int> visited(n, 0);
//         for (int i = 0; i < n; i++)
//         {
//             if (visited[i] == 0)
//             {
//                 vector<int> visPersons(n, 0);
//                 int curr = i;
//                 int dist = 0;
//                 while (true)
//                 {
//                     int nextPerson = favorite[curr];
//                     if (visited[curr] == 1)
//                     {
//                         break;
//                     }
//                     if (visPersons[curr] == 1)
//                     {
//                         int cycleLength = distance - visitedPersons[nextPerson];
//                         if (cycleLength == 2)
//                         {
//                             unordered_set<int> visitedNodes = {current, nextPerson};
//                             twoCycleInvitations += 2 + bfs(curr, visitedNodes) + bfs(nextPerson, visitedNodes);
//                             break;
//                         }
//                         visPersons[curr] = dist++;
//                         visited[curr] = 1;
//                         curr = nextPerson;
//                     }
//                 }
//             }
//         }
//     }
// };

int main()
{
    vector<int> v;
    v.insert(v.begin(), 1);
    cout<<v[0]<<"\n";
}