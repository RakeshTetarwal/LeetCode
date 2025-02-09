#include<iostream>
#include<string>
#include<vector>
using namespace std;

void computeLPS(vector<int>& lps, string& pat){
    int len = 0, i = 1;
    lps[0] = 0;
    int m = pat.length();
    while(i<m){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len == 0){
                lps[i] = 0;
                i++;
            }else{
                len = lps[len - 1];
            }
        }
    }
}


int main(){
    // LPS calculation
    string text, pat;
    cin>>text>>pat;
    int m = pat.length();
    vector<int> lps(m, 0);
}