#include<iostream>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        /*
            dp[i][j] represents the cost of bursting the balloons from index i to j
            let k be the last burst balloon then cost of bursting this balloons will
            be nums[i-1]*nums[k]*nums[j] and if this is the last burst balloon then 
            balloons on its left and right are already brusted.
            So dp[i][j] = dp[i][k-1] + dp[k+1][j] + cost_k

        */
       int n = nums.size();
       vector<int> data(n+2, 1);
       for(int i=1;i<=n;i++){
            data[i] = nums[i-1];
       }
       vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));
       for(int i=1;i<=n;i++){
        dp[i][i] = data[i];
       }
       for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=i+1;k<=j-1;k++){
                dp[i][j] = min(dp[i][k-1] + dp[k+1][j] + data[k]*data[i-1]*data[j+1], dp[i][j]);
            }
        }
       }
       return dp[1][n];
    }
};

int main(){
    
}