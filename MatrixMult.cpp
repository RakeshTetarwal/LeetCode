#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int mod = (1e9) + 7;
    vector<vector<long long>> mult(vector<vector<long long>>& res, vector<vector<long long>>& m){
        int n1 = res.size();
        int m1 = res[0].size();
        int n2 = m.size();
        int m2 = m[0].size();
        vector<vector<long long>> f(n1, vector<long long>(m2, 0));
        if(m1 != n2){
            exit(1);
        }
        for(int i=0;i<n1;i++){
            for(int j=0;j<m2;j++){
                for(int k=0;k<m1;k++){
                    f[i][j] = (f[i][j] + res[i][k]*m[k][j]%mod)%mod;
                }
            }
        }
        return res;
    }
    void matrix_mult(vector<vector<long long>>& m, int t){
        int n = m.size();
        vector<vector<long long>> res(n, vector<long long>(n, 0));
        for(int i=0;i<n;i++){
            res[i][i] = 1;
        }
        while(t){
            if(t&1)
                res = mult(res, m);
            m = mult(m, m);
            t = t>>1;
        }
        for(int i = 0;i<n;i++){
            for(int j=0;j<n;j++){
                m[i][j] = res[i][j];
            }
        }
    }
    int lengthAfterTransformations(int n, int t, vector<vector<long long>>& v) {

        vector<vector<long long>> start(n, vector<long long>(1, 1));
        // for(int i=0;i<n;i++){
        //     start[i][i] = 1;
        // }
        matrix_mult(v, t);
        start = mult(v, start);
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j=0;j<1;j++){
                ans = (ans + start[i][j])%mod;
            }
        }

        return ans;
    }
};

int main(){
    int n, k;
    cin>>n>>k;
    vector<vector<long long>> v(n, vector<long long>(n, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    Solution s;
    cout<<(s.lengthAfterTransformations(n, k, v))<<"\n";

}