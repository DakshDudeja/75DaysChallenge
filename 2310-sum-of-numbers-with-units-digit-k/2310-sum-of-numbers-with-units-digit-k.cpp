class Solution {
public:
    int solve(int i,int num,int k,vector<vector<int>>&dp){
        if(num==0) return 0;
        
        if(i > num || num<0) return 1e9;
        if(dp[i][num]!=-1) return dp[i][num];
        
        int pick = 1 + solve(i,num-i,k,dp);
        int notPick= solve(i+10,num,k,dp);
        
        return dp[i][num]=min(pick,notPick);
    }
    int minimumNumbers(int num, int k) {
        if(k==0 and num ==0) return 0;
        if(k==0) return num%10==0 ? 1:-1;
        if(num==0) return 0;
        vector<vector<int>>dp(num+2,vector<int>(num+2,-1));
        int ans= solve(k,num,k,dp);
        return ans >= 1e9 ? -1 : ans;
    }
};