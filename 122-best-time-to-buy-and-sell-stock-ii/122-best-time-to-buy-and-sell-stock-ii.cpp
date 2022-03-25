class Solution {
public: 
    int solve(int i,int canBuy,vector<int>&prices, vector<vector<int>>&dp){  //i=current day
        if(i>=prices.size() ) return 0;
        if(dp[i][canBuy]!=-1) return dp[i][canBuy];
        
        int idle = solve(i+1,canBuy,prices,dp);
        
        int buy,sell=0;
        if(canBuy==1){
             buy = -prices[i] + solve(i+1,0,prices,dp);
        }
        else{
             sell = prices[i] + solve(i+1,1,prices,dp);
        }
         return dp[i][canBuy] = max(idle,max(buy,sell));
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int> >dp(prices.size(),vector <int>(2,-1));

        return solve(0,1,prices,dp);
    }
};