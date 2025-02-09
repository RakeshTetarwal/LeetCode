#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
class Solution {
public:
    struct Trie
    {
        unordered_map<int, Trie*> next;
        int count = 0;
    };
    
    using ll = long long;
    ll ans = 0;
    long long countPrefixSuffixPairs(vector<string>& words) {
        Trie* t = new Trie();
        for(auto& word: words){
            Trie* tmp = t;
            for(int i=0, n = word.length(); i<n; i++){
                char ch = word[i], ch2 = word[n-i-1];
                tmp = tmp->next.insert({(ch-'a')*26 + (ch2-'a'), new Trie()}).first->second;
                ans += tmp->count;
            }
            tmp->count++;
        }
        return ans;
    }
};
int main(){
    
}