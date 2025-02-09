#include<iostream>
using namespace std;
int main(){
    string s = "ahnsk";
    s += ""+to_string(123);
    cout<<s<<"\n";
}