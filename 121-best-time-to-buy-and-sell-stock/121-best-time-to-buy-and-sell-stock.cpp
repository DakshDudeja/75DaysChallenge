class Solution {
public:
    int solve(int i,int canBuy,int k,vector<int>& prices,vector<vector<vector<int>>>&dp){
        if(i>=prices.size() || k<=0) return 0;
        
        if(dp[i][canBuy][k]!=-1) return dp[i][canBuy][k];
        
        int idle = solve(i+1,canBuy,k,prices,dp);
        int a=0,b=0;
        if(canBuy){
             a = -prices[i] + solve(i+1,0,k,prices,dp);
        }
        else
            b = +prices[i] + solve(i+1,1,0,prices,dp);
        
        return dp[i][canBuy][k] = max(idle,max(a,b));
        
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return solve(0,1,1,prices,dp);

    }
};
// 7,1,5,3,6,4
//idle = 
//a=