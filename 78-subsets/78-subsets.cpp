class Solution {
public:
    vector<vector<int>>res;
    void solve(int i,vector<int>&nums,vector<int>&temp){
        if(i>=nums.size()){
            res.push_back(temp);
            return;   
        }
        
        //include krega
        temp.push_back(nums[i]);
        solve(i+1,nums,temp);
        temp.pop_back();
        solve(i+1,nums,temp);
        
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        solve(0,nums,temp);
        return res;
    }
};