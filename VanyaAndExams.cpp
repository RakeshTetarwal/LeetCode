#include <iostream>
#include <vector>
#include <map>
#include <queue>
typedef long long ll;

using namespace std;

void take_input_2d_vector(int n, int m, vector<vector<int>> &v)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
}

void take_input_1d_vector(int n, vector<int> &v)
{
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
}

void fill_maps(map<int, int> &hor, map<int, int> &vert, vector<vector<int>> &v)
{
    int n = v.size();
    int m = v[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            hor[v[i][j]] = i;
            vert[v[i][j]] = j;
        }
    }
}

void solve()
{
    ll n, k;
    cin>>n>>k;
    ll ans = 0;
    ll x = k;
    while(x*k<=n && k != 1){
        x =x*x;
    }
    while(n){
        while(x>n){
            x/=k;
        }
        n-=x;
        ans++;
    }
    cout<<ans<<"\n";
}

int main()
{
    int t = 1;
    cin>>t;
    while (t--)
    {
        solve();
    }
}