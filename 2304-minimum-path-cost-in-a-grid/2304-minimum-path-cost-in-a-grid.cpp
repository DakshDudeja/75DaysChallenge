class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid, vector<vector<int>>& moveCost,vector<vector<int>>&dp){
        if(i>=grid.size() || j>=grid[0].size()) return 0;
        if(i==grid.size()-1) return grid[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
            
        int mini1=INT_MAX,res=0;
        for(int k=0;k<grid[i].size();k++){
            // cout<<res<<endl;
             res = grid[i][j]+moveCost[grid[i][j]][k]+ solve(i+1,k,grid,moveCost,dp);
            mini1=min(mini1,res);
        }
        return dp[i][j]=mini1;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n=grid.size(),m=grid[0].size();
        int mini=INT_MAX;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        for(int i=0;i<m;i++){
            int ans = solve(0,i,grid,moveCost,dp);
            mini=min(ans,mini);
        }
        return mini;
    }
};