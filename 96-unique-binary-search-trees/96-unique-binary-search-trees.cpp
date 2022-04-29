class Solution {
public:
    int dp[22];
    int solve(int n){
        if(n<=1) return 1;
        
        if(dp[n]!=-1) return dp[n];
        
        int ways=0;
        for(int i=0;i<n;i++){
            ways+=solve(i)*solve(n-i-1);
        }
        return dp[n]=ways;
    }
    int numTrees(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};