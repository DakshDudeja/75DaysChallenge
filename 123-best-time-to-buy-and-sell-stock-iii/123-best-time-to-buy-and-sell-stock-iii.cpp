class Solution {
public:
      int solve(int i,int canBuy,int transCount,vector<int>&prices, vector<vector<vector<int> > >&dp){  //i=current day
        if(i>=prices.size() or transCount <= 0) return 0;
        if(dp[i][canBuy][transCount]!=-1) return dp[i][canBuy][transCount];
        
        int idle = solve(i+1,canBuy,transCount,prices,dp);
        
        int buy,sell=0;
        if(canBuy==1){
             buy = -prices[i] + solve(i+1,0,transCount,prices,dp);
        }
        else{
             sell = prices[i] + solve(i+1,1,transCount-1,prices,dp);
        }
         return dp[i][canBuy][transCount] = max(idle,max(buy,sell));
    }
    int maxProfit(vector<int>& prices) {
         vector<vector<vector<int> > > dp (prices.size(),vector<vector<int> >(2,vector <int>(3,-1)));

        return solve(0,1,2,prices,dp);
    }
};