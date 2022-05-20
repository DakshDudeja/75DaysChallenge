class Solution {
public:
    int path(int i,int j,int m ,int n,vector<vector<int>>&dp,vector<vector<int>>& obstacleGrid){
        
        if(i>=m || j>=n) return 0;
        if(obstacleGrid[i][j]==1) return 0;

        if(i==m-1 and j==n-1){
            return 1;
        }
        if(obstacleGrid[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int right = path(i+1,j,m,n,dp,obstacleGrid);
        int left = path(i,j+1,m,n,dp,obstacleGrid);
        
        return dp[i][j] = right+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         int p = obstacleGrid.size();
        int q = obstacleGrid[0].size();
        vector<vector<int>>dp(p+1,vector<int>(q+1,-1));
        return path(0,0,p,q,dp,obstacleGrid);
    }
};