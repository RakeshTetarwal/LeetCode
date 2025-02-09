#include <iostream>
#include <algorithm>
#include <vector>
/*
    USE DP and Binary Search
*/
typedef long long int ll;
using namespace std;

void solve()
{
    ll n, x;
    cin>>n>>x;
    vector<ll> a(n), pre_sum(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pre_sum[i] = (i == 0 ? 0 : pre_sum[i - 1]) + a[i];
    }
    vector<ll> dp(n + 1, 0);
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int l = i, r = n;
        while (l < r)
        {
            int m = (l + r) >> 1;
            ll s = (pre_sum[m] - pre_sum[i] + a[i]);
            if (s > x)
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        dp[i] = ((l == n)? 0 : dp[l + 1]) + (l - i);
        ans += dp[i];

    }
    cout << ans << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
