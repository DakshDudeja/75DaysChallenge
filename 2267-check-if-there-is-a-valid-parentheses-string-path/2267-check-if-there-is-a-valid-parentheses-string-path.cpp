class Solution {
public:
    int n,m;
    vector<vector<vector<int>>> dp;
    bool dfs(int i,int j,vector<vector<char>>& g,int cnt){     // cnt = number of opening brackets remaining
        if(i<0 || j<0 || i>=n || j>=m) return 0;
        
        if(dp[i][j][cnt]!=-1) return dp[i][j][cnt];
        
        if(i==n-1 && j==m-1){
            if(g[i][j]=='(') cnt++;
            else cnt--;
            
            if(cnt<0) return 0;
            if(cnt==0) return 1;
            
            return dp[i][j][cnt] = 0;
        }
        
        if(g[i][j] == '('){
            if(dfs(i+1,j,g,cnt+1)) return 1;
            if(dfs(i,j+1,g,cnt+1)) return 1;
        }
        else{
            if(cnt == 0) return dp[i][j][cnt] = 0;
            if(dfs(i+1,j,g,cnt-1)) return 1;
            if(dfs(i,j+1,g,cnt-1)) return 1;
        }
        
        return dp[i][j][cnt]=0;
    }
	
    bool hasValidPath(vector<vector<char>>& g) {
        n = g.size(), m = g[0].size();
        dp = vector<vector<vector<int>>>(n,vector<vector<int>>(m,vector<int>(m+n+1,-1)));
        return dfs(0,0,g,0);
    }
};