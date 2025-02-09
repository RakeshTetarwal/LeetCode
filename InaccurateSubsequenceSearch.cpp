
#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define ll long long
#define PII std::pair<long long, long long>

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
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n),b(m);
    map<int, int> mp_a, mp_b;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
        mp_a[a[i]]++;
        mp_b[b[i]]++;
    }
    int count = 0;
    for(auto i:mp_b){
        if(mp_a.count(i.first)){
            count+=min(i.second, mp_a[i.first]);
        }
    }
    int ans = (count>=k);
    for(int i=m; i<n;i++){
        int j=i-m;
        int removed = a[j], added = a[i];
        mp_a[removed]--;
        mp_a[added]++;
        // cout<<added<<" "<<mp_a[added]<<"\n";
        // cout<<removed<<" "<<mp_a[removed]<<"\n";
        if(mp_b.count(added) && mp_b[added] >= mp_a[added]){
            count+= (added != removed);
        }
        if(mp_b.count(removed) && mp_b[removed] > mp_a[removed]){
            count-= (added != removed);
        }
        if(count>=k){
            ans++;
        }
    }
    cout<<ans<<"\n";




}


int main(){

    long long t;
    cin>>t;
    while(t--){
        solve();
    }

}