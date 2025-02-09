#include<iostream>
using namespace std;
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        bitset<32> bs1(num1), bs2(num2);
        int bits = 0;
        for(int i=0;i<32;i++){
            if(bs2[i] == 1){
                bits++;
            }
        }
        int ans = 0;‰
        for(int i=0;i<32;i++){
            if(bs1[i] == 1 && bits){
                ans = (ans | (1<<i));
                bits--;
            }
        }
        for(int i=0;i<bits;i++){
            if(!(ans &(1<<i))){
                ans = (ans | (1<<i));
            }
        }
        return ans;
    }
};