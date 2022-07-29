class Solution {
public:
    int solve(int i,int currZ,int currO,int m,int n,vector<string>&strs,vector<vector<vector<int>>>&dp){
        if(i>=strs.size() || currZ > m || currO > n ){
            return 0;
        }
        if(dp[i][currZ][currO]!=-1) return dp[i][currZ][currO];
        
        int one=0,zero=0;
        for(int j=0;j<strs[i].size();j++){
            if(strs[i][j]=='0') zero+=1;
            else
                one+=1;
        }
       //not pick
        int notpick = 0 + solve(i+1,currZ,currO,m,n,strs,dp);
        
        //pick
        int pick=INT_MIN;                                        
        if(currZ+zero <= m and currO+one <= n){
          pick = 1 + solve(i+1,currZ+zero,currO+one,m,n,strs,dp); 
        }

        return dp[i][currZ][currO]=max(pick,notpick);
        
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
       int sz=strs.size();
       vector<vector<vector<int>>>dp(sz+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
       return solve(0,0,0,m,n,strs,dp); 
    }
};