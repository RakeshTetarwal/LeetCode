#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> find_max_num(vector<int> &nums, int len)
    {
        int n = nums.size();
        vector<int> ans;
        int k = n - len;
        for (int i = 0; i < n; i++)
        {
            if (ans.empty())
            {
                ans.push_back(nums[i]);
            }
            else
            {
                while (!ans.empty() && ans.back() < nums[i] && k)
                {
                    ans.pop_back();
                    k--;
                }
                ans.push_back(nums[i]);
            }
        }
        while (k)
        {
            ans.pop_back();
        }
        return ans;
    }

    vector<int> merge_nums(vector<int> &n1, vector<int> &n2)
    {
        int l1 = n1.size();
        int l2 = n2.size();
        vector<int> ans(l1 + l2);

        int i = 0, j = 0, k=0;
        while (i < l1 || j < l2)
        {
            if(i == l1){
                ans[k++] = n2[j++];
            }else if(j==l2){
                ans[k++] = n1[i++];
            }else{
                if(n1[i] > n2[j]){
                    ans[k++] = n1[i++];
                }else{
                    ans[k++] = n2[j++];
                }
            }
        }
        return ans;
    }

    void check_num(vector<int>& ans, vector<int> & tmp, int len){
        for(int i=0;i<len;i++){
            if(ans[i] < tmp[i]){
                ans = tmp;
                return;
            }else if(tmp[i] < ans[i]){
                return;
            }
        }
    }


    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<int> ans(k, -1);
        for (int i = 1; i < k; i++)
        {
            vector<int> n1 = find_max_num(nums1, i);
            vector<int> n2 = find_max_num(nums2, k - i);
            vector<int> n = merge_nums(n1, n2);
            check_num(ans, n, k);
        }
        return ans;
    }
};

int main()
{
}