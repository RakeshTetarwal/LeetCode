#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minimumDifference(vector<int> &nums)
    {
        int n = nums.size();
        int N = n >> 1;
        int sum = 0;
        for (auto num : nums)
            sum += num;
        vector<int> left[N + 1], right[N + 1];
        for (int i = 0; i < N; i++)
        {
            int j = N;
            int ind = 0;
            int k = i;
            int sum1 = 0, sum2 = 0;
            int elems = 0;
            while (k)
            {
                if (k & 1)
                {
                    sum1 += nums[ind];
                    sum2 += nums[j + ind];
                    elems++;
                }
                k = k >> 1;
                ind++;
            }
            left[elems].push_back(sum1);
            right[elems].push_back(sum2);
        }
        for(int i=0;i<N;i++){
            sort(right[i].begin(), right[i].end());
        }
        int ans = abs(sum - 2*(*left[N].begin()));
        for(int i=1;i<N;i++){
            for(auto a:left[i]){
                int b = (sum - (a<<1))>>1;
                int ind_b = N - i;
                auto& v = right[ind_b];
                auto itr = lower_bound(v.begin(), v.end(), b);
                if(itr != v.end()){
                    ans = min(ans, abs(sum - 2*(a + *itr)));
                }
                if(itr != v.begin()){
                    auto it = itr;
                    it--;
                    ans = min(ans, abs(sum - 2*(a + *it)));
                }
            }
        }
        return ans;
    }
};

int main()
{
}