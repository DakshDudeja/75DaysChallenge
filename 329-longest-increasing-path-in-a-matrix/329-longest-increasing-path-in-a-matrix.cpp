class Solution {
public:
    int dp[201][201];
    int solve(int i,int j,int prev,int m,int n,vector<vector<int>>&matrix){
        if(i<0 || j<0 || i>=n || j>=m || prev >= matrix[i][j]) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int a = 1 + solve(i+1,j,matrix[i][j],m,n,matrix);
        int b = 1 + solve(i,j+1,matrix[i][j],m,n,matrix);
        int c = 1 + solve(i-1,j,matrix[i][j],m,n,matrix);
        int d = 1 + solve(i,j-1,matrix[i][j],m,n,matrix);
        
        return dp[i][j]=max({a,b,c,d});

            
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int maxi=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int t=solve(i,j,-1,m,n,matrix);
                maxi=max(maxi,t);
            }
        }
        return maxi;
    }
};