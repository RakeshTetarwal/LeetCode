/*

This is the implementation of Rabin Carp algorithm to find all occurance of
any string in some other string or maximum length substring in the original string.

*/

#include <iostream>
#include <vector>
#include<unordered_set>
#define ull unsigned long long
#define d 131
using namespace std;

class Solution
{
public:
    string ans;
    int mod = int(1e9+7);
    bool solve(in len, string& s, int power){
        ull hash = 0;
        for(int i=0;i<len;i++){
            hash = (hash*31 + int(s[i] - 'a' + 1))%mod;
        }
        unordered_set<int> st;
        st.insert(hash);
        for(int i=len; i<s.length();i++){
            hash = (hash - power*(int(s[i] - 'a' + 1)) + mod)%mod;
            hash = (hash*31 + int(s[i] - 'a' +1))%mod;
            if(st.find(hash) != st.end()){
                string tmp = s.substr(i-len+1, len);
                if(ans.length() < tmp.length()){
                    ans = tmp;
                }
                return true;
            }
        }
        return false;
    }
    void bin_search(int l, int r, string &s, vector<int> &power)
    {
        int m = (l+r)>>1;
        if(solve(m+1, s, power[m])){
            l = mid+1;
        }else{
            r = m-1;
        }
        solve(l,r, s, power[m]);
        return ans;
    }

    string longestDupSubstring(string s)
    {
        int n = s.length();
        vector<int> power(n, 1);
        ull tmp = 1;
        for (int i = 1; i < n; i++)
        {
            tmp = (tmp * 31) % mod;
            power[i] = tmp;
        }
        bin_search(0, n - 1, s, power);
    }
};

int main()
{
    string s;
    cin >> s;
    cout << find_ans(s) << "\n";
}