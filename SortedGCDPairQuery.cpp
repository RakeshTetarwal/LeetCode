#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<long long> cnt_divisors(vector<int> &nums)
    {
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> mp(mx + 1, 0);
        for (auto num : nums)
            mp[num]++;
        vector<long long> gcdValue(mx + 1, 0);
        long long ans = 0;
        for (int i = mx; i >= 0; i--)
        {
            int cnt1 = 0; // This will store how many number are divisible by i
                          // Ex: i = 10, mx = 100 => cnt1 = 10;
            int sub = 0;  // This will store the repeatations
            for (int j = i; j <= mx; j += i)
            {
                sub += gcdValue[i];
                cnt1 += mp[i];
            }
            gcdValue[i] = 1LL * cnt1 * (cnt1 - 1) / 2 - sub;
        }
        for(int i=1;i<=mx;i++){
            gcdValue[i] += gcdValue[i-1];
        }
        return gcdValue;
    }

    vector<int> gcdValues(vector<int> &nums, vector<long long> &queries)
    {
        int mx = *max_element(nums.begin(), nums.end());
        vector<long long> ans = cnt_divisors(nums);
        vector<int> f_ans(int(queries.size()));
        for(int i=0;i<queries.size(); i++){
            long long query = queries[i];
            f_ans[i] = lower_bound(ans.begin(), ans.end(), query);
        }
        return f_ans;
    }
};

int main()
{
}