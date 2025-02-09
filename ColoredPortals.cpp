#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int INF = 1e9;
const string vars[] = {"BG", "BR", "BY", "GR", "GY", "RY"};


void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      char s[5];
      cin >> s;
      a[i] = find(vars, vars + 6, s) - vars;
    }
    vector<vector<int>> lf(n), rg(n);
    for (int o = 0; o < 2; ++o) {
      vector<int> last(6, -INF);
      for (int i = 0; i < n; ++i) {
        last[a[i]] = (o ? n - i - 1 : i);
        (o ? rg[n - i - 1] : lf[i]) = last;
      }
      reverse(a.begin(), a.end());
    }
    int s, d;
    while(q--){
        cin>>s>>d;
        s--, d--;
        int ans = INF;
        for(int i=0;i<6;i++){
            if(a[s] + i != 5 && a[d] + i != 5){
                cout<<min(int(abs(lf[s][i] - s)) + int(abs(lf[s][i] - d)), 
                        int(abs(rg[s][i] - s)) + int(abs(rg[s][i] - d)))<<"\n";
                ans = min(ans, 
                min(int(abs(lf[s][i] - s)) + int(abs(lf[s][i] - d)), 
                    int(abs(rg[s][i] - s)) + int(abs(rg[s][i] - d))));
            }
        }
        if(ans > INF/2)ans=-1;
        cout<<ans<<"\n";
    }

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

