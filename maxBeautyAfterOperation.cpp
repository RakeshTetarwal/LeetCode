#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int MN = INT_MIN, MX = INT_MAX;
        int ans = 0;
        int curr = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mx = INT_MIN;
        int i=0, j=0;
        mx = nums[i] + k;
        while(j<n){
            int mn = nums[j] - k;
            if(mn > mx){
                ans = max(ans, j-i);
                i++;
                mx = nums[i] + k;
            }else{
                j++;
            }
        }
        ans = max(ans, j-i+1);
        return ans;
    }
};
int main(){

}