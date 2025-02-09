#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        queue<string> q;
        int len = 0;
        int n = words.size();
        vector<string> ans;
        for (int i = 0; i < n; i++)
        {
            int t_len = words[i].length();
            if (len + t_len > maxWidth)
            {
                int x = maxWidth - len;
                int q_len = q.size();
                if (q_len == 1)
                {
                    string res = q.front();
                    q.pop();
                    while (x)
                    {
                        res.push_back(' ');
                        x--;
                    }
                    ans.push_back(res);
                }
                else
                {
                    string res = "";
                    int space = (x) / (q_len - 1);
                    while (!q.empty())
                    {
                        res += q.front();
                        q.pop();
                        int tmp = space;
                        while(tmp && x){
                            res.push_back(' ');
                            tmp--, x--;
                        }
                    }
                    int new_len = res.length();
                    while(new_len < maxWidth){
                        res.push_back(' ');
                        new_len++;
                    }
                    ans.push_back(res);
                }
            }
        }
        return ans;
    }
};

int main()
{
}