#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        queue<string> q;
        vector<int> ans;
        unordered_set<string> strs;
        int n = s.length();
        int m = words.size();
        int i = 0, j = 0;
        while (j < n)
        {
            string tmp = s.substr(j, m);
            if (strs.find(tmp) != strs.end())
            {
                while(q.front() != tmp)
                {
                    strs.erase(q.front());
                    q.pop();
                    i += m;
                }
                q.pop();
                i += m;
            }
            strs.insert(s.substr(j, m));
            q.push(tmp);
            if(q.size() == words.size()){
                ans.push_back(i);
            }
            
        }
        return ans;
    }
};
