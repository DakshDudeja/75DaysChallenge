class Solution {
public:
    int solve(int n,int i,vector<int>&dp,vector<int>&cost){
        if(i==n) return 0;
        if(i>n) return INT_MAX;
        if(dp[i]!=0) return dp[i];
        return dp[i] = cost[i]+min(solve(n,i+1,dp,cost),solve(n,i+2,dp,cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,0);
        int a= solve(n,0,dp,cost);
        int b = solve(n,1,dp,cost);
        return min(a,b);
    }
};