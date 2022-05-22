class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>>dp(s.length(),vector<bool>(s.length()));
        int count=0;
        for(int g=0;g<s.length();g++){
            
            for(int i=0,j=g ; j<dp.size() ; i++,j++){
                if(g==0){
                    dp[i][j]=true;
                }
                else if(g==1){
                   if(s[i]==s[j]){
                       dp[i][j]=true;
                   }
                    else
                        dp[i][j]=false;
                }
                else{
                    if(s[i]==s[j] and dp[i+1][j-1] == true){
                        dp[i][j]=true;
                    }
                    else
                        dp[i][j]=false;
                }
                if(dp[i][j]) count++;
            }
        }
        return count;
    }
};