#include <iostream>
#include <vector>
#include<map>

using namespace std;

void take_input_2d_vector(int n, int m, vector<vector<int>>& v){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
}

void take_input_1d_vector(int n, vector<int>& v){
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
}

void fill_maps(map<int, int>& hor, map<int, int>& vert, vector<vector<int>>& v){
    int n=v.size();
    int m = v[0].size();
    for(int i=0;i<n; i++){
        for(int j=0;j<m;j++){
            hor[v[i][j]] = i;
            vert[v[i][j]] = j;
        }
    }
}

void solve()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    take_input_2d_vector(n, m, a);
    take_input_2d_vector(n, m, b);
    map<int, int> hori, vert;
    fill_maps(hori, vert, b);
    map<int, int> hor_swap, vert_swap;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int e = a[i][j];
            int i1 = (hori.find(e)->second);
            int j1 = (vert.find(e)->second);
            if((hor_swap.count(i) && hor_swap[i] != i1)){
                cout<<"No\n";
                return;
            }
            if((vert_swap.count(j) && vert_swap[j] != j1)){
                cout<<"No\n";
                return;
            }
            hor_swap[i] = i1;
            vert_swap[j] = j1;

        }
    }
    cout<<"Yes\n";

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