class Solution {
public:
    int solve(int idx,int canBuy,int transCount,vector<int>& prices,vector<vector<vector<int> > >&dp){
        if(idx>=prices.size() or transCount <= 0) return 0;
        if(dp[idx][canBuy][transCount]!=-1) return dp[idx][canBuy][transCount];

        int idle = solve(idx+1,canBuy,transCount,prices,dp);

        int b=0,s=0;
        if(canBuy==1)
            b = -prices[idx]+solve(idx+1,0,transCount,prices,dp);
        else
            s = +prices[idx]+solve(idx+1,1,transCount-1,prices,dp);
        
         return dp[idx][canBuy][transCount] = max(idle,max(b,s));
    }
    int maxProfit(vector<int>& prices) {
    vector<vector<vector<int> > > dp (prices.size(),vector<vector<int> >(2,vector <int>(2,-1)));

        return solve(0,1,1,prices,dp);
    }
};