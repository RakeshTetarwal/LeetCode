#include<iostream>
#include<vector>
using namespace std;
#define ll long long

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int chars[n];

    bool is_zero = false;
    for(int i=0;i<n;i++){
        chars[i] = s[i] - '0';
        if (chars[i] == 0){
            is_zero = true;
        }
    }
    if (n<=2){
        if (chars[0] == 0 && chars[1] == 0){
            cout<<0<<"\n";
        }else if(chars[0] == 0){
            cout<<chars[1]<<"\n";
        }else{
            cout<<s<<"\n";
        }
        return;
    }
    if(n==3){
        if (chars[0] == 0 || chars[n-1] == 0){
            cout<<0<<"\n";
            return;
        }else{
            int ans = INT_MAX;
            ans = min(ans, min(chars[0]*10 + chars[1] + chars[2], (chars[0]*10 + chars[1]) * chars[2]));
            ans = min(ans, min(chars[0] + chars[1] * 10 + chars[2], (chars[0]) * (chars[1] * 10 + chars[2])));
            cout << ans <<"\n";
            return;
        }
    }
    if (is_zero){
        cout<<0<<"\n";
        return;
    }
    int ans = INT_MAX;
    for (int i=0;i<n-1;i++){
        int num = chars[i]*10 + chars[i+1];
        int post = 0, pre = 0;
        int post_all_one = true, pre_all_one = true;
        for (int j=i+2;j<n;j++){
            if(chars[j] != 1){
                post_all_one = false;
                post += chars[j];
            }
        }
        for (int j=i-1; j>=0; j--){
            if (chars[j] != 1){
                pre_all_one = false;
                pre += chars[j];
            }
        }
        if(pre_all_one && post_all_one){
            ans = min(ans, num);
        }else if(pre_all_one){
            ans = min(ans, num + post);
        }else if(post_all_one){
            ans = min(ans, num + pre);
        }else{
            ans = min(ans, num + pre + post);
        }

    }
    cout<<ans<<"\n";
}


int main(){

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}