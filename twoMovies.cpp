#include<iostream>
#include<vector>
using namespace std;
int main(){

    int t;
    cin>>t;
    int n;
    vector<int> a(2*(1e5) + 10), b(2*(1e5) + 10);
    while(t--){
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        int A=0, B=0;
        int remaining_neg = 0, remaining_pos = 0;
        for(int i=0; i<n; i++){
            cin>>b[i];
        }
        for(int i=0; i<n; i++){
            if (a[i] * b[i] > 0){
                remaining_neg += a[i] < 0? 1 : 0;
                remaining_pos += a[i] > 0? 1 : 0;
            }else if(a[i]>0 && b[i]<=0){
                A+=1;
            }else if(a[i]<=0 && b[i]>0){
                B+=1;
            }else{
                continue;
            }
        }

        int m = min(A, B);
        int M = max(A, B);
        int diff = M - m;
        if (diff > remaining_neg + remaining_pos){
            cout<< (m + remaining_pos)<<"\n";
        } else{
            cout << ((A + B + remaining_pos - remaining_neg)>> 1) <<"\n";
        }



    }

}