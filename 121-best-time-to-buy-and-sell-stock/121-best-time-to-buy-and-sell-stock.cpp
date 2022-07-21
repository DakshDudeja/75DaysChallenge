class Solution {
public:
    int solve(int i,int canBuy,int k,vector<int>& prices,vector<vector<int>>&dp){
        if(i>=prices.size() || k<=0) return 0;
        
        if(dp[i][canBuy]!=-1) return dp[i][canBuy];
        
        int idle = solve(i+1,canBuy,k,prices,dp);
        int buy=0,sell=0;
        if(canBuy){
             buy = -prices[i] + solve(i+1,0,k,prices,dp);
        }
        else
          sell = +prices[i] + solve(i+1,1,k-1,prices,dp);
        
        return dp[i][canBuy] = max(idle,max(buy,sell));
        
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,1,prices,dp);

    }
};
