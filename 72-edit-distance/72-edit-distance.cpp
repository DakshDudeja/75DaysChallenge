class Solution {
public:
    int solve(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s1[i]==s2[j]) 
            return dp[i][j] =  0+solve(i-1,j-1,s1,s2,dp);
        else{
            int a = 1+solve(i,j-1,s1,s2,dp); //insert
            int b = 1+solve(i-1,j,s1,s2,dp); //delete
            int c = 1+solve(i-1,j-1,s1,s2,dp);  //replace
            return dp[i][j]=min(a,min(b,c));
        }
            
        return 0;
    }
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(word1.size()-1,word2.size()-1,word1,word2,dp);
    }
};