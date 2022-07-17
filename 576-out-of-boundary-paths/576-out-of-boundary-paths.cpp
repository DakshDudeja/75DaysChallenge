class Solution {
public:
    int dp[51][51][51];
    long long solve(int i,int j,int m,int n,int k){
        if(k<0) return 0;
        if(i<0 || i>=m || j<0 || j>=n){
            return 1;
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        long long a =solve(i+1,j,m,n,k-1);
        long long b =solve(i,j+1,m,n,k-1);
        long long c =solve(i-1,j,m,n,k-1);
        long long d = solve(i,j-1,m,n,k-1);
        
        return dp[i][j][k]=(a+b+c+d)%1000000007;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof dp);
        return solve(startRow,startColumn,m,n,maxMove);
    }
};