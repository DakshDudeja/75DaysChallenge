class Solution {
public:
    int dp[13][10001];
    int solve(int idx,int amount, vector<int>&coins){
        if(amount==0) return 0;
        // if(idx==coins.size()-1 and amount==0) return 1;
        if(idx>=coins.size() || amount<0) return 100000;
        
        int consider=100000;
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        if(coins[idx]<=amount){
            consider = 1 + solve(idx,amount-coins[idx],coins);
        }
        int notConsider= solve(idx+1,amount,coins);
        
        return dp[idx][amount]=min(consider,notConsider);
    }
    int coinChange(vector<int>& coins, int amount) {
          memset(dp,-1,sizeof(dp));
          int ans=solve(0,amount,coins);
          if(ans==100000) return -1;
        else
            return ans;
    }
};