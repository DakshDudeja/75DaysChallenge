class Solution {
public:
    int dp[201][1001];
    int solve(int i,vector<int>&nums,int target){
        if(i>=nums.size()) return 0;
        if(target==0) return 1;
        if(dp[i][target]!=-1) return dp[i][target];
        
        int consider=0;
        if(target-nums[i]>=0){
            consider = solve(0,nums,target-nums[i]);
        }
        int notConsider = solve(i+1,nums,target);
        
        return dp[i][target] = consider+notConsider;
        
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums,target);
    }
};