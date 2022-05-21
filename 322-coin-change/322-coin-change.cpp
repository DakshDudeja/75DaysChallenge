class Solution {
public:
    int unbounded_coin(int curridx, vector<int>& coins, int amount,vector<vector<int>>&dp){
        if (amount == 0) return 0;
        if(curridx >= coins.size()) return 100000;  //any maximum value 
        
        if(dp[curridx][amount]!=-1) return dp[curridx][amount];
        int consider = 100000;
        
        if(coins[curridx]<=amount){
            consider = 1 + unbounded_coin(curridx,coins,amount-coins[curridx],dp);
        }
        int notConsider = unbounded_coin(curridx+1,coins,amount,dp);
        
        return dp[curridx][amount] = min(consider,notConsider);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        int ans = unbounded_coin(0,coins,amount,dp);
        if(ans==100000) return -1;
        else
            return ans;
                              
    }
};