class Solution {
public:
    vector<vector<int>>res;    
    void solve(int idx,vector<int>&nums){
        if(idx==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int j=idx;j<nums.size();j++){
            swap(nums[idx],nums[j]);
            solve(idx+1,nums);
            swap(nums[j],nums[idx]);
        }
        
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        solve(0,nums);
        return res;
    }
};