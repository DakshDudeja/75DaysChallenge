class Solution {
public:
    int solve(int i,int prevIdx,vector<int>&nums,vector<vector<int>>&dp){
        if(i==nums.size()) return 0;
        
        if(dp[i][prevIdx+1]!=-1) return dp[i][prevIdx+1];
        int len= solve(i+1,prevIdx,nums,dp);
        
        if(prevIdx==-1 or nums[i]>nums[prevIdx]){
             len=max(len,1+solve(i+1,i,nums,dp));    
        }
        return dp[i][prevIdx+1]=len;
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
       return solve(0,-1,nums,dp);
    }
};