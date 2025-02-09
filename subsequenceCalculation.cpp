#include <iostream>
using namespace std;

string minWindow(string S, string T)
{
    // Write your Code here
    int i1 = 0, j1 = 0, j2 = 0;
    int ans = INT_MAX;
    int i = 0, j = 0;
    while (j1 < S.length())
    {
        if (S[j1] == T[j2])
        {
            j1++;
            j2++;
        }else{
            j1++;
        }
        if (j2 == T.length())
        {
            if(ans > j1 - i1){
                ans = min(ans, j1 - i1);
                i = i1;
                j = j1 - 1;
            }
            i1++;
            j1 = i1;
            j2 = 0;
        }
    }
    return S.substr(i, ans == INT_MAX? 0: ans);
}

int main()
{
    int t;
    cin>>t;
    string S, T;
    while(t--){
        cin>>S>>T;
        cout<<minWindow(S, T)<<"\n";
    }
}