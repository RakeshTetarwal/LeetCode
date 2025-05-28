#include<iostream>
using namespace std;

class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string low = to_string(start);
        string high = to_string(finish);
        int n = high.length();
        low = string(n-low.length(), '0') + low;
        int pre_n = n - s.length();
        vector<long long> dp(n, -1);
        function<long long(int, bool, bool)> dfs = [&](int i, bool limitLow, bool limitHigh) -> long long{
            if(i == n){
                return 1;
            }
            if(!limitLow && !limitHigh && dp[i] != -1){
                return dp[i];
            }
            int lo = (limitLow)?(low[i]-'0'):0;
            int hi = (limitLow)?(low[i]-'0'):0;
            long long ans = 0;
            if(i<pre_n){
                for(int x=lo;x<=min(hi, limit);x++){
                    ans += dfs(i+1, limitLow && (x==lo), limitHigh&&(x==hi));
                }
            }else{
                int x = (s[i-pre_n] - '0');
                if(x>=lo && x <=min(hi, limit)){
                    ans += dfs(i+1, limitLow && (x==lo), limitHigh&&(x==hi));
                }
            }
            if (!limit_low && !limit_high) {
                dp[i] = ans;
            }
            return ans;
        }
        return dfs(0, true, true);
    }
};

int main(){

}