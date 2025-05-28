#include<iostream>
using namespace std;

class Solution {
public:
    int idealArrays(int n, int maxValue) {
        vector<int> sieve(maxValue, 0);
        vector<int> factors[maxValue];
        for(int i=2;i<=maxValue;i++){
            if(sieve[i] == 0){
                for(int j = i;j<=maxValue;j+=i){
                    sieve[j] = i;
                }
            }
        }
        for(int i=2;i<=maxValue;i++){
            int x = i;
            int k = sieve[i];
            int cnt = 0;
            while(x%k == 0){
                x/=k;
                cnt++;
            }
            factors[i].push_back(cnt);
        }
        vector<vector<int>> C(16, vector<int>(n+20, 0));
        C[0][0] = 1;
        for(int i=1;i<C.size();i++){
            C[i][0] = 1;
            for(int j = 1;j<C[i].size();j++){
                C[i][j] = C[i-1][j] + C[i-1][j-1];
            }
        }
        int mod = (1e9) + 7;
        int ans = 0;
        for(int i=1;i<=maxValue;i++){
            long long mul = 1;
            for(int j:factors){
                mul = (mul*C[i+j-1][j-1])%mod;
            }
            ans = (ans + mul)%mod;
        }
        return ans;
    }

};


int main(){

}