#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int k = (random())%n + 1;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        v[i] = random();
    }
    vector<int> leftMax(n), rightMax(n);
    leftMax[0] = v[0], rightMax[n-1] = v[n-1];
    for(int i=1;i<n;i++){
        if(i%k==0){
            leftMax[i] = v[i];
        }else{
            leftMax[i] = max(leftMax[i-1], v[i]);
        }
    }
    for(int i=n-2;i>=0;i--){
        if((i+1)%k==0){
            rightMax[i] = v[i];
        }else{
            rightMax[i] = max(rightMax[i+1], v[i]);
        }
    }
    vector<int> ans;
    for(int i=0;i<n-k+1;i++){
        ans.push_back(max(rightMax[i], leftMax[i+k-1]));

    }
    return ans;
}