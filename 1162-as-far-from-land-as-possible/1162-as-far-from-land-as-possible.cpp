class Solution {
public:
    int maxDistance(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1)
                    q.push({i,j});
                else
                    mat[i][j]=-1;
            }
        }
        if(q.size()==0 || q.size()==m*n) return -1;
        vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
        while(!q.empty()){
            int currR = q.front().first;
            int currC= q.front().second;
            q.pop();
            
            for(auto it:dir){
                int i = currR + it[0];
                int j = currC + it[1];
                
                if(i>=0 and j>=0 and i<m and j<n and mat[i][j]<0){
                    q.push({i,j});
                    mat[i][j]=mat[currR][currC]+1;
                }
            }
        }
        int maxi=-1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){      
                maxi=max(mat[i][j],maxi);
            }
        }    
    return maxi-1; //kyuki jisko maanke add kr rhe hai voh 1 hai 0 nhi for reference 01 matrix dekh lena
    }
};