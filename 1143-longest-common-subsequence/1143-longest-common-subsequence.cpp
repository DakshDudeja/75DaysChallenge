class Solution {
public:
    int solve(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        if(i<0 || j<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j] = 1+solve(i-1,j-1,s,t,dp);
        }
        return dp[i][j]=max(solve(i-1,j,s,t,dp),solve(i,j-1,s,t,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,text1,text2,dp);
    }
};