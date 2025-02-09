#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

class Solution
{
public:
    ll low = -(1e9);
    ll high = (1e9);
    ll ans;
    bool isPossible(vector<int> &nums1, vector<int> &nums2, long long x, ll k)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        ll count = 0;
        for (int i = 0; i < n1; i++)
        {
            int a1 = nums1[i];
            if(a1 > 0){
                int lb = floor(float(x)/a1);
                ll ind = lower_bound(nums2.begin(), nums2.end(), lb) - nums2.begin();
                count += ind;
            }else if(a1 < 0){
                int ub = ceil(float(x)/a1);
                ll ind = upper_bound(nums2.begin(), nums2.end(), ub) - nums2.begin();
                count += (n2 - ind);
            }else{
                if(x>=0){
                    count += (n2);
                }
            }
            if(count >= k){
                return true;
            }
        }
        return count >= k;
    }
    long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, long long k)
    {
        while (low <= high)
        {
            ll mid = (low + high) >> 1;
            if (isPossible(num1, num2, m, k))
            {
                ans = mid;
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
}
