class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        if(m==0 || n==0) return mat;
        
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    vis[i][j]=true;
                }
            }
        }
        vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
        while(!q.empty()){
            int size=q.size();
            while(size-- >0){
                int currR = q.front().first;
                int currC= q.front().second;
                q.pop();

                for(auto it:dir){
                    int i = currR + it[0];
                    int j = currC + it[1];

                    if(i>=0 and j>=0 and i<m and j<n and vis[i][j]==false){

                        q.push({i,j});
                        mat[i][j]=mat[currR][currC]+1;
                        vis[i][j]=true;
                    }
                }
            }
            
            
        }
        return mat;
    }
};