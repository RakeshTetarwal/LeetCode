#include<iostream>
#include<vector>
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
    int seq[n];
    for(int i=0;i<n;i++){
        cin>>seq[i];
    }
    int invalid_index = check_gcd(n, seq);
    if(invalid_index == -1){
        cout<<"YES\n";
        return;
    }
    int i_removed[n-1];
    int i1_removed[n-1];
    int i2_removed[n-1];
    int ind = 0, ind1 = 0, ind2 = 0;
    for(int i=0;i<n;i++){
        if(i!=invalid_index){
            i_removed[ind++] = seq[i];
        }
        if(i != invalid_index + 1){
            i1_removed[ind1++] = seq[i];
        }
        if(i != invalid_index + 2){
            i2_removed[ind2++] = seq[i];
        }
    }
    if(check_gcd(n-1, i_removed) == -1){
        cout<<"YES\n";
        return;
    }
    if(check_gcd(n-1, i1_removed) == -1){
        cout<<"YES\n";
        return;
    }
    if(check_gcd(n-1, i2_removed) == -1){
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
    


}


int main(){

    long long t;
    cin>>t;
    while(t--){
        solve();
    }

}