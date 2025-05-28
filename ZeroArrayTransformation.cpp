#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> used_q;
        priority_queue<int> available_q;
        sort(queries.begin(), queries.end());
        int q_ind=0;
        int t_used = 0;
        for(int i=0;i<n;i++){
            while(q_ind<queries.size() && queries[q_ind][0] == i){
                available_q.push(queries[q_ind][1]);
                q_ind++;
            }
            while(nums[i] > 0 && !available_q.empty()){
                used_q.push(available_q.top());
                available_q.pop();
                nums[i]--;
                t_used++;
            }
            if(nums[i] > 0){
                return -1;
            }
            while(!used_q.empty() && used_q.top() == i){
                used_q.pop();
            }
        }
        return queries.size() - t_used;
    }
};
int main(){

}