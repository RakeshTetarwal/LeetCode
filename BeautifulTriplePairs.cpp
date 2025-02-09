#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define ll long long

int rec_gcd(int a, int b){
    return b? rec_gcd(b, a%b) : a;

}
int non_rec_gcd(int a, int b){
    while(b){
        a = a%b;
        a = (a+b);
        b = a-b;
        a = a-b;
    }
    return a;
}

int check_gcd(int n, int arr[]){
    int gcd[n-1];
    for(int i=0;i<n-1;i++){
        gcd[i] = rec_gcd(arr[i], arr[i+1]);
    }
    for(int i=0;i<n-2;i++){
        if(gcd[i]>gcd[i+1]){
            return i;
        }
    }
    return -1;
}

void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    map<pair<int,int>, ll> freq_12, freq_23, freq_13;
    map<pair<int, pair<int,int> >, ll> freq_123;
    for(int i=0;i<n-2;i++){
        pair<int,int> p_12 = make_pair(a[i], a[i+1]), p_23 = make_pair(a[i+1], a[i+2]), p_13 = make_pair(a[i], a[i+2]);
        pair<int, pair<int,int> > p_123 = make_pair(a[i], make_pair(a[i+1], a[i+2]));
        freq_12[p_12]++;
        freq_23[p_23]++;
        freq_13[p_13]++;
        freq_123[p_123]++;
    }
    ll ans = 0;

    for (int i = 0; i < n - 2; i++) {        
        pair<int,int> p1 = make_pair(a[i], a[i+1]), p2 = make_pair(a[i+1], a[i+2]), p3 = make_pair(a[i], a[i+2]);
        pair<int, pair<int,int> > p_123 = make_pair(a[i], make_pair(a[i+1], a[i+2]));
        ans += freq_12[p1] - freq_123[p_123];
        ans += freq_23[p2] - freq_123[p_123];
        ans += freq_13[p3] - freq_123[p_123];
    }
    cout<<(ans>>1)<<"\n";

}


int main(){

    long long t;
    cin>>t;
    while(t--){
        solve();
    }

}