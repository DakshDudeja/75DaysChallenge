class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int i){
        //mark visited
        isConnected[i][i]=0;
        for(int j=0;j<isConnected.size();j++){
            if(isConnected[i][j]==1){
                isConnected[i][j]=0;
                //check that connected node is visited or not, if not then visit all                     it's connected nodes
                if(isConnected[j][j]==1)
                    dfs(isConnected,j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(isConnected[i][i]==0)continue;
                ans++;
                dfs(isConnected,i);
        }
        return ans;
    }
};