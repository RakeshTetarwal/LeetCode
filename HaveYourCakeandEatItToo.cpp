#include<iostream>
#include<vector>
using namespace std;
#define ll long long


void print_result(long long i1, long long a1, long long b1, long long i2, long long a2, long long b2, long long i3, long long a3, long long b3){
    long long result[3][2];
    result[i1][0] = a1, result[i1][1] = b1;
    result[i2][0] = a2, result[i2][1] = b2;
    result[i3][0] = a3, result[i3][1] = b3;
    for(long long i=0;i<3;i++){
        cout<<result[i][0]<<" "<<result[i][1]<<" ";
    }
    cout<<"\n";
}

void solve(){
    long long n;
    cin>>n;
    long long a[3][n];
    for(long long i=0;i<3;i++){
        for(long long j=0;j<n;j++){
            cin>>a[i][j];
            if(j>0){
                a[i][j] += a[i][j-1];
            }
        }
    }
    long long total = a[0][n-1];
    long long perm[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
    for(long long i=0; i<6; i++){
        long long i1 = perm[i][0];
        long long i2 = perm[i][1];
        long long i3 = perm[i][2];
        for(long long j=0;j<n;j++){

            if(a[i1][j] >= (total + 2)/3){
                int l = j, r = n-1;
                while(l<r){
                    int m = (l+r)>>1;
                    if((a[i2][m] - a[i2][j] >= (total + 2)/3)){
                        r = m;
                    }else{
                        l = m + 1;
                    }
                }
                if (a[i3][n-1] - a[i3][l] >= (total + 2)/3){
                    print_result(i1, 1, j + 1, i2, j + 2, l+1, i3, l+2, n);
                    return;
                }
            }
        }
    }
    cout<<-1<<"\n";

}


int main(){

    long long t;
    cin>>t;
    while(t--){
        solve();
    }

}