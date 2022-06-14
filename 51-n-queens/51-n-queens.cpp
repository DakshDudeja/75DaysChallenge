class Solution {
public:
    vector<vector<string>>res;
    bool isSafe(int m ,int n,vector<string>&grid){
        //column
        for(int i=m,j=n;i>=0;i--){
            if(grid[i][j]=='Q') return false;
        }
        //left diagonal
        for(int i=m,j=n;i>=0 and j>=0;i--,j--){
            if(grid[i][j]=='Q') return false;
        }
        //right diagonal
        for(int i=m,j=n;i>=0 and j<grid[i].size();i--,j++){
            if(grid[i][j]=='Q') return false;
        }
        return true;
    }
    void solve(int i,vector<string>&temp,vector<string>&grid,int n){
        if(i>=n){
            res.push_back(grid);
            return;
        }
        for(int k=0;k<n;k++){
            if(isSafe(i,k,grid)){
                grid[i][k]='Q';
                solve(i+1,temp,grid,n);
                grid[i][k]='.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        // vector<vector<string>>grid(n,vector<string>(n,"."));
        vector<string> grid(n,string(n,'.'));   //1d ke andar 2d vector bana diya 

        vector<string>temp;
        solve(0,temp,grid,n);
        return res;
        
    }
};

//grid iterate 
//issafe
//mark true
//iterate full
//mark false