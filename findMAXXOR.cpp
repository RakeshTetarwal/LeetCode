#include<iostream>
#include<vector>
using namespace std;

class TrieNode{
    TrieNode* child[2];
    public:
    TrieNode(){
        child[0] = nullptr;
        child[1] = nullptr;
    }
    public:
    void insert(int x){
        TrieNode* t = this;
        bitset<32> bs(x);
        for(int i=0;i<32;i++){
            int bit = bs[i];
            if(!(t->child[bit])){
                t->child[bit] = new TrieNode;
            }
            t = t->child[bit];
        }
    }
    int find_max_xor_for_element(int num){
        bitset<32> bs(num);
        int ans = 0;
        TrieNode* t = this;
        for(int i=0;i<32;i++){
            if(t->child[!bs[i]]){
                ans = (ans|1)<<1;
                t = t->child[!bs[i]];
            }else{
                ans = ans<<1;
                t = t->child[bs[i]];
            }
        }
        return ans;
    }
    int findXORmax(vector<int>& nums){
        for(auto num:nums){
            this->insert(num);
        }
        int ans = 0;
        for(auto num: nums){
            ans = max(ans, this->find_max_xor_for_element(num));
        }
        return ans;
    }
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode t;
        return t.findXORmax(nums);
    }
};

int main(){

}

