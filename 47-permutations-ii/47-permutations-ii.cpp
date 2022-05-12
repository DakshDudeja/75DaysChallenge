class Solution {
public:
    vector<vector<int>>res;
    void solve(vector<int>&nums,int idx){
        if(idx==nums.size()){
            res.push_back(nums);
            return;
        }
        unordered_set<int> seen;  

        for(int i=idx;i<nums.size();i++){
            if(seen.find(nums[i])!= seen.end()) continue;
            swap(nums[idx],nums[i]);
            solve(nums,idx+1);
            swap(nums[i],nums[idx]);
            seen.insert(nums[i]);
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        solve(nums,0);
        return res;
    }
};