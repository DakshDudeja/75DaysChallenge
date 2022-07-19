class Solution {
public:
    queue<pair<int,int>>q;
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>&vis){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || vis[i][j]==true || grid[i][j]==0) return;
        vis[i][j]=true;
        q.push({i,j});
        dfs(i+1,j,grid,vis);
        dfs(i,j+1,grid,vis);
        dfs(i-1,j,grid,vis);
        dfs(i,j-1,grid,vis);
        
        return;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int flag=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid,vis);
                    flag=1;
                    break;
                }
            }
            if(flag==1) break;
        }
        int cnt=0;
        vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
        while(!q.empty()){
            int size=q.size();
            cnt++;
            while(size-- >0){
                int currR=q.front().first;
                int currC=q.front().second;
                q.pop();
                
                for(auto it:dir){
                    int i=currR+it[0];
                    int j=currC+it[1];
                    
                    
                    if(i>=0 and j>=0 and i<n and j<m and vis[i][j]==false){
                     if(grid[i][j]==1) return cnt-1; 
                    else
                        q.push({i,j});
                        vis[i][j]=true;
                    }
                }
            }
        }
        return -1;
    }
};