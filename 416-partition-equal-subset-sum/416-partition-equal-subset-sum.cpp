class Solution {
public:
    int solve(int i,vector<int>&arr,int sum, vector<vector<int>>&dp){
        if(sum==0)return true;
        if(i>=arr.size() || sum<0)return false;
        if(dp[i][sum]!=-1) return dp[i][sum];
        
        int a=0,b=0;
        if(sum-arr[i] >= 0){
                a=solve(i+1,arr,sum-arr[i],dp);
            }
        b = solve(i+1,arr,sum,dp);
        
        return dp[i][sum]=a || b;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto x:nums) sum+=x;
        if(sum%2!=0)return false;
          vector<vector<int>> dp(nums.size()+1,vector<int>(sum+1,-1));
        return solve(0,nums,sum/2,dp);
    }
};