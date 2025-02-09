#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    void dfs(string prefix, set<string> &visited, int n, int k, string &ans)
    {
        for (int i = 0; i < k; i++)
        {
            string temp = prefix + to_string(i);
            if (visited.find(temp) != visited.end())
                continue;
            visited.insert(temp);
            dfs(temp.substr(1, n - 1), visited, n, k, ans);
            ans.push_back('0' + i);
        }
    }

    string crackSafe(int n, int k)
    {
        string prefix(n - 1, '0');
        set<string> visited;
        string ans = prefix;
        dfs(prefix, visited, n, k, ans);
        return ans;
    }
};

int main()
{
    Solution s;
    cout<<s.crackSafe(2, 2)<<"\n";
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
        }
    }
}
