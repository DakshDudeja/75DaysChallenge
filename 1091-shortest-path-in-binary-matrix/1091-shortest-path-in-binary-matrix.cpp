class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
     int n=grid.size() , m =grid[0].size();
        queue<int>que;
        
        int pathCount =0,time=0;
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;
    
       
        que.push(grid[0][0]);
        
        vector<vector<int>> dir ={{0,1},{0,-1},{1,0},{-1,0},{-1,1},{1,1},{1,-1},{-1,-1}};
        
        while(que.size()!=0){
            int size = que.size();
            while(size-- > 0){
                int idx = que.front();
                que.pop();
                
                int sr = idx / m ,sc = idx % m;
                
                 if(sr==n-1 and sc==m-1)
                        return time+1;
                for(vector<int>& d : dir){
                    int r = sr + d[0];
                    int c = sc + d[1];
                    
                    if(r>=0 and c>=0 and r<n and c<m and grid[r][c] == 0){
                    grid[r][c]=2;
                    que.push(r*m+c);
         
                   
                    }
                }
            }
            time++;
        }
        return -1;
    }
};