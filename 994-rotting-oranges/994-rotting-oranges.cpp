class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int total=0;
        queue<int>q;
        int m=grid[0].size(),n=grid.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)total++;
                
                if(grid[i][j]==2)q.push(i*m+j);
            }
        }
        if(total==0)return 0;
        vector<vector<int>>direction = {{1,0},{0,1},{-1,0},{0,-1}};

        int res=0;
        while(!q.empty()){
            //bfs
            int size=q.size();
            while(size-- >0){
                int curr=q.front();
                q.pop();

                int row=curr/m ,col=curr%m;


                for(auto dir:direction){
                    int i=dir[0]+row;
                    int j=dir[1]+col;

                    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!=1) continue;

                    grid[i][j]=2;
                    q.push(i*m+j);
                    total--;
                    if(total==0) return res+1;
                }
            }
           res++;                     
        }
        return -1;
    }
};
