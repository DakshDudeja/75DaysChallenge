class Solution {
public:
    int dp[201][201];
    int solve(int i,int j,vector<vector<int>>&grid){
        // if(i>=grid.size() || j>=grid[0].size()) return INT_MAX;
        
        if(i==grid.size()-1 and j==grid[0].size()-1) return grid[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int a=INT_MAX,b=INT_MAX;
         if(i+1<grid.size()) a= grid[i][j] + solve(i+1,j,grid);
         
         if(j+1<grid[0].size()) b= grid[i][j] + solve(i,j+1,grid);

        
        return dp[i][j]=min(a,b);
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        memset(dp,-1,sizeof(dp));
        return solve(0,0,grid);
    }
};