#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    long mod = int(1e9 + 7);
    string s;
    long find_ans(int ind, int lower_limit, int upper_limit, int match_ind, vector<int>& v1, vector<int>& v2, vector<int>& v, vector<vector<vector<int>>>& dp){
        cout<<ind<<" "<<lower_limit<<" "<<upper_limit<<" "<<match_ind<<"\n";
        cout<<s<<"\n";

        if(match_ind == v.size()){
            return 0;
        }
        if(ind == v1.size()){
            // cout<<s<<"\n";
            return 1;
        }
        // if(dp[ind][lower_limit* 2+ upper_limit][match_ind] != -1){
        //     // cout<<s<<"\n";
        //     return dp[ind][lower_limit* 2+ upper_limit][match_ind];
        // }
        long ans = 0;
        // cout<<(lower_limit? v1[ind]: 0)<<" "<<(upper_limit?v2[ind]:25)<<" "<<lower_limit<<" "<<upper_limit<<" "<<ind<<"\n";
        for(int i=(lower_limit? v1[ind]: 0); i<=(upper_limit?v2[ind]:25); i++){
            // cout<<ind<<" "<<i<<"\n";
            s.push_back(char('a' + i));
            ans = (ans + find_ans(ind+1, lower_limit && i==v1[ind] ,(upper_limit&&(i==v2[ind])), (i==v[match_ind]? match_ind+1: 0), v1, v2, v, dp))%mod;
            s.pop_back();
        }
        return dp[ind][lower_limit* 2+ upper_limit][match_ind] = ans;
    }

    int findGoodStrings(int n, string s1, string s2, string evil) {
        vector<int> v1(n), v2(n), v(int(evil.length()));
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(5, vector<int>(evil.length()+1, -1)));
        for(int i=0;i<n; i++){
            v1[i] = int(s1[i] - 'a');
            v2[i] = int(s2[i] - 'a');
        }
        
        for(int i=0;i<evil.length(); i++){
            v[i] = int(evil[i] - 'a');
        }
        
        return find_ans(0, 1, 1, 0, v1, v2, v, dp);

    }
};

int main(){
    Solution s;
    std::string s1 = "pzdanyao";
    std::string s2 = "wgpmtywi";
    std::string evil = "sdka";
    cout<<s.findGoodStrings(8, s1, s2, evil)<<"\n";
}

