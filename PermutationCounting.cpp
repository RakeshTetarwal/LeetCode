
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<long long, long long>

long long rec_gcd(long long a, long long b){
    return b? rec_gcd(b, a%b) : a;

}
long long non_rec_gcd(long long a, long long b){
    while(b){
        a = a%b;
        a = (a+b);
        b = a-b;
        a = a-b;
    }
    return a;
}

long long check_gcd(long long n, long long arr[]){
    long long gcd[n-1];
    for(long long i=0;i<n-1;i++){
        gcd[i] = rec_gcd(arr[i], arr[i+1]);
    }
    for(long long i=0;i<n-2;i++){
        if(gcd[i]>gcd[i+1]){
            return i;
        }
    }
    return -1;
}

class Compare {
public:
    bool operator()(PII below, PII above)
    {
        if (below.first > above.first) {
            return true;
        }
        else if (below.first == above.first
                 && below.second > above.second) {
            return true;
        }

        return false;
    }
};

void solve(){
    long long n, k;
    cin>>n>>k;
    vector<long long> a(n);
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(),a.end());
    
    long long cnt = 0, last = a.back();
    while(!a.empty() && a.back() == last){
        cnt++;
        a.pop_back();
    }
    while(!a.empty()){
        long long delta = (a.back() - last);
        if(delta*cnt > k){
            break;
        }
        k -= delta*cnt;
        last = a.back();
        while(!a.empty() && a.back() == last){
            cnt++;
            a.pop_back();
        }
    }
    last += k/cnt;
    k %= cnt;
    cnt -= k;
    cout<<(n*last - cnt + 1)<<"\n";
}


int main(){

    long long t;
    cin>>t;
    while(t--){
        solve();
    }

}