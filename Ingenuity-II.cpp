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
    string s;
    cin>>s;
    map<char, int> hash_map;
    hash_map['N'] = hash_map['S'] = hash_map['E'] = hash_map['W'] = 0;
    for(int i=0;i<n;i++){
        hash_map[s[i]]++;
    }
    if(((hash_map['N'] + hash_map['S'])&1) != 0 ||((hash_map['E'] + hash_map['W'])&1 )!= 0){
        cout<<"NO\n";
        return;
    }
    bool cond1 = hash_map['N'] + hash_map['S'] == 2;
    bool cond2 = hash_map['E'] + hash_map['W'] == 2;
    if(n==2){
        if((cond1 || cond2) && (s[0] != s[1])){
            cout<<"NO\n";
            return;
        }
    }
    
    int vert = hash_map['N'] + hash_map['S'];
    int hori = hash_map['E'] + hash_map['W'];
    int rover_north = (hash_map['N'] + 1)>>1, rover_south = (hash_map['S'] + 1) >> 1;
    int rover_east = (hash_map['E'] + 1)>>1, rover_west = (hash_map['W'] + 1) >> 1;
    int heli_north = (hash_map['N'])>>1, heli_south = (hash_map['S']) >> 1;
    int heli_east = (hash_map['E'])>>1, heli_west = (hash_map['W']) >> 1;
    if(n==4){
        if(cond1 && cond2){
            if(hash_map['N'] == hash_map['S'] && hash_map['E'] == hash_map['W']){
                heli_north = 1;
                heli_south = 1;
                rover_east = 1;
                rover_west = 1;
            }
        }
    }
    for(int i=0;i<n;i++){
        switch (s[i])
        {
        case 'N':
            if(heli_north){
                cout<<"H";
                heli_north--;
            }else if(rover_north){
                cout<<"R";
                rover_north--;
            }
            break;
        case 'S':
            if(heli_south){
                cout<<"H";
                heli_south--;
            }else if(rover_south){
                cout<<"R";
                rover_south--;
            }
            break;
        
        case 'E':
            if(heli_east){
                cout<<"H";
                heli_east--;
            }else if(rover_east){
                cout<<"R";
                rover_east--;
            }
            break;
        
        case 'W':
            if(heli_west){
                cout<<"H";
                heli_west--;
            }else if(rover_west){
                cout<<"R";
                rover_west--;
            }
            break;
        default:
            break;
        }
    }
    cout<<"\n";

}


int main(){

    long long t;
    cin>>t;
    while(t--){
        solve();
    }

}