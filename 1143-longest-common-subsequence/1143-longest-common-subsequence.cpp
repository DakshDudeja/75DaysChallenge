class Solution {
public:
    int dp[1005][1005];
    int solve(int i,int j,string &s1,string &s2){
        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s1[i]==s2[j]){
            return dp[i][j]=1+solve(i-1,j-1,s1,s2);
        }
        
        return dp[i][j]=max(solve(i-1,j,s1,s2) , solve(i,j-1,s1,s2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return solve(text1.size()-1,text2.size()-1,text1,text2);
    }
};