#include <iostream>
#include <vector>
#include <time.h>
#include <pthread.h>
#include <set>
using namespace std;

vector<int> cf_digits = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
string str = "";

int dfs(vector<int> &num, int ind, int limit)
{
    if (ind == num.size())
    {
        return 1;
    }
    int ans = 0;
    int max_limit = limit ? num[ind] : 9;
    for (int i = 0; i <= max_limit; i++)
    {
        if (cf_digits[i] != -1)
        {
            if (limit)
            {
                ans += dfs(num, ind + 1, limit && i == max_limit);
            }
        }
    }
    return ans;
}

class Solution
{
public:
    int confusingNumberII(int n)
    {
        string s = to_string(n);
        int d[10] = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
        auto check = [&](int x) -> bool
        {
            int y = 0;
            for (int t = x; t; t /= 10)
            {
                int v = t % 10;
                y = y * 10 + d[v];
            }
            return x != y;
        };
        function<int(int, int, int)> dfs = [&](int pos, int limit, int x) -> int
        {
            if (pos >= s.size())
            {
                return check(x);
            }
            int up = limit ? s[pos] - '0' : 9;
            int ans = 0;
            for (int i = 0; i <= up; ++i)
            {
                if (d[i] != -1)
                {
                    ans += dfs(pos + 1, limit && i == up, x * 10 + i);
                }
            }
            return ans;
        };
        return dfs(0, 1, 0);
    }
};

double time1, timedif, time2;
;
int main()
{
    Solution s;
    double total_time_1 = 0, total_time_2 = 0;
    for (int n = 0; n <= 2e5; n++)
    {
        time1 = (double)clock();
        time1 = time1 / CLOCKS_PER_SEC;
        s.confusingNumberII(n);
        timedif = (((double)clock()) / CLOCKS_PER_SEC) - time1;
        total_time_1 += timedif;
        time2 = (double)clock();
        time2 = time2 / CLOCKS_PER_SEC;
        s.confusingNumberII(n);
        timedif = (((double)clock()) / CLOCKS_PER_SEC) - time2;
        total_time_2 += timedif;
        if (n % (10000) == 0)
        {
            cout << n << "\n";
        }
    }
    cout << total_time_1 << " " << total_time_2 << "\n";
}
