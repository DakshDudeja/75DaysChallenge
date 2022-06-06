class Solution {
public:
    int solve(int i,int canBuy,int transCount,vector<int>&prices,vector<vector<int>>&dp){
        if(i>=prices.size() or transCount <= 0)return 0;
        if(dp[i][canBuy]!=-1) return dp[i][canBuy];
        int buy=0,sell=0;
        int notConsider=solve(i+1,canBuy,transCount,prices,dp);

        if(canBuy)
            buy= -prices[i] + solve(i+1,0,transCount,prices,dp);
        else
            sell= prices[i] +solve(i+1,1,transCount-1,prices,dp);

        return dp[i][canBuy]= max(notConsider,max(buy,sell));
        
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solve(0,1,1,prices,dp);
    }
};