int mooresVotingAlgo(vector<int>& nums){
    int majority_element = nums[0];
    int freq = 1;
    for(int i=1;i<nums.size();++i){
        if(nums[i]!=majority_element)   freq--;
        else                            freq++;
        
        if(freq==0){
            majority_element = nums[i];
            freq = 1;
        }
    }
    return majority_element;
}

/*
    its an algo efficient algorithm used to find the majority element in an array
    For example: arr = [2,3,2,5,2]
    The above algo will return the 2.



*/