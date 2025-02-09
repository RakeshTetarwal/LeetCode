#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>

class DSU{
    public:
    vector<int> par;
    DSU(int n){
        par = vector<int>(n);
        for(int i=0;i<n;i++){
            par[i] = i;
        }
    }
    int find_par(int i){
        if(par[i] == i){
            return i;
        }
        return par[i] = find_par(i);
    }
    void _union(int i, int j){
        int p_i = find_par(i), p_j = find_par(j);
        if(p_i > p_j){
            swap(p_i, p_j);
        }
        par[p_j] = p_i;
    }
};

class Solution {
public:

    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        DSU d(n);
        vector<array<int, 2>> ind(n);
        for(int i=0;i<n;i++){
            ind[i] = {arr[i], i};
        }
        sort(arr.begin(), arr.end());
        int x = 0, y = 1;
        while(y<n){
            if(int(abs(arr[x][0] - arr[y][0])) <= limit){
                d._union(arr[x][1], arr[y][1]);
            }
            x++;
            y++;
        }
        vector<int> ans(n);
        x = 0, y = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        while(y<n){
            int px = d.find_par(arr[x][1]);
            int py = d.find_par(arr[y][1]);
            if(px == py){
                y++;
            }else{
                while(x<y){
                    pq.push(arr[x][1]);
                    x++;
                }
                while(!pq.empty()){
                    ans[pq.top()] = arr[x][0];
                    pq.pop();
                    x++;
                }
            }
        }
        return ans;
    }
};

int main() {
    std::vector<int> arr = {4, 2, 7, 1, 5};
    std::vector<int> smallestArray = getSmallestArray(arr);

    std::cout << "Smallest array: ";
    for (int num : smallestArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}