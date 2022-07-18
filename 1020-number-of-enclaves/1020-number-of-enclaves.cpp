class Solution {
public:
    void solve(int i,int j,vector<vector<int>>&grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0) return;
        
        grid[i][j]=0;
        solve(i+1,j,grid);
        solve(i,j+1,grid);
        solve(i,j-1,grid);
        solve(i-1,j,grid);
        
        return;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 and j<m and grid[i][j]==1) solve(i,j,grid);
                if(i<n and j==0 and grid[i][j]==1) solve(i,j,grid);
                if(i==n-1 and j<m and grid[i][j]==1) solve(i,j,grid);
                if(j==m-1 and i<n and grid[i][j]==1) solve(i,j,grid);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)cnt++;
            }
        }
        return cnt;
    }
};