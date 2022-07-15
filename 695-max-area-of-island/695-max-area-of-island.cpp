class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>>q;
        int cnt=0,ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    int curArea = 0;
                    grid[i][j]=0;
                    
                    while(!q.empty()){
                        int currR = q.front().first;
                        int currC= q.front().second;
                        q.pop();
                        
                        curArea++;
                        
                        vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
                        for(auto it:dir){
                            int row = it[0]+currR;
                            int col = it[1]+currC;

                            if(row < 0 || col <0 || row>=n || col >=m || grid[row][col]==0) continue;

                            if(grid[row][col]==1) {
                                cnt++;
                                q.push({row,col});
                                grid[row][col]=0;
                            }
                        }
                    }
                  
                    if(curArea > ans) ans=curArea;
                }
            }
        }
        return ans;            
    }
};