class Solution {
public:
    int solve(int i,int j,int n,vector<vector<int>>& t, vector<vector<int>>&dp){
        if(i>=n || j>=n)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        int a = t[i][j] +solve(i+1,j,n,t,dp);
        int b= t[i][j] +solve(i+1,j+1,n,t,dp);
        
        return dp[i][j]=min(a,b);
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));

        return solve(0,0,n,triangle,dp);
    }
};