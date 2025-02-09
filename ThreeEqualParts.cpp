#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int cnt_1 = 0;
        int n = arr.size();
        for (auto i : arr) {
            cnt_1 += i;
        }
        if (cnt_1 % 3 != 0) {
            return {-1, -1};
        }
        if(cnt_1 == 0){
            return {0, 2};
        }
        int k = cnt_1 / 3;
        int i1 = 0, j1 = 0, i2 =0, j2 =0 , i3 =0, j3 =0;
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                tmp++;
                if (tmp == 1)
                    i1 = i;
                if (tmp == k + 1)
                    i2 = i;
                if (tmp == 2 * k + 1)
                    i3 = i;
                if (tmp == k)
                    j1 = i;
                if (tmp == 2 * k)
                    j2 = i;
                if (tmp == 3 * k)
                    j3 = i;
            }
        }
        // cout<<i1<<" "<<j1<<"\n"<<i2<<" "<<j2<<"\n"<<i3<<" "<<j3<<"\n";
        int p1 = i1, p2 = i2, p3 = i3;
        while (p1 < j1 && p2 < j2 && p3 < j3) {
            if (arr[p1] != arr[p2] || arr[p1] != arr[p3]) {
                return {-1, -1};
            }
            p1++, p2++, p3++;
        }
        if(p1!=j1 || p2!=j2 || p3 != j3){
            return {-1, -1};
        }
        int z1 = (i2 - j1 - 1), z2 = (i3 - j2 - 1), z3 = (n - j3 - 1);
        if (z3 > min(z1, z2)) {
            return {-1, -1};
        }
        return {j1 + z3, j2 + z3 + 1};
    }
};

int main(){

}
