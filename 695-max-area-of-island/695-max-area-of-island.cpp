class Solution {
public:
    vector<int>par,size;
    int findPar(int u){
        return par[u] == u ? u : (par[u] = findPar(par[u]));
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        if(n==0) return 0;
        int m= grid[0].size();
        
        for(int i=0;i<n*m;i++){
            par.push_back(i);
            size.push_back(1);
        }
        
        vector<vector<int>> dir {{0,1},{0,-1},{1,0},{-1,0}};
        int maxSize=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    int p1 = findPar(i*m+j);
                    for(vector<int>&d: dir){
                        int r = i+d[0];
                        int c = j+d[1];
                        
                        if(r>=0 && c>=0 and r<n and c<m and grid[r][c]==1){
                            int p2= findPar(r*m+c);
                            if(p1!=p2){
                                par[p2] = p1;
                                size[p1] += size[p2];
                            }
                        }
                    }
                    maxSize = max(maxSize,size[p1]);
                }
            }
        }
        return maxSize;
    }
};