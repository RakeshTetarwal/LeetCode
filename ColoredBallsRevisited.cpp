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
    int n;
    cin>>n;
    int ans = -1;
    int c = -1;
    int tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(tmp > c){
            c = tmp;
            ans = i;
        }
    }    
    cout<<ans<<"\n";

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