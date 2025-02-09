#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int find_ans(int p, int i, int j, vector<int> &boxes, vector<vector<vector<int>>> &dp)
    {
        if (i > j)
        {
            return 0;
        }
        if (dp[p][i][j] != -1)
        {
            return dp[p][i][j];
        }
        int ans = (s+1)*(s+1) + find_ans(0, i+1, j, boxes, dp);
        for(int k=i+1; k<j;k++){
            if(boxes[i] == boxes[k]){
                ans = max(ans, find_ans(0, i, k-1, boxes, dp) + find_ans(p+1, k+1, j, boxes, dp));
            }
        }
        return dp[p][i][j] = ans;
    }

    int removeBoxes(vector<int> &boxes)
    {
        int n = boxes.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(n, -1)));
        find_ans(0, 0, n - 1, boxes, dp);
    }
};

int main()
{
}