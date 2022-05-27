class Solution {
public:
    int solve(int i,int j,vector<int>&cuts,vector<vector<int>>&dp){
        if(i>j) return 0;
        int mini=INT_MAX;
        if(dp[i][j]!=-1)return dp[i][j];
        for(int idx=i;idx<=j;idx++){
            int cost = cuts[j+1]-cuts[i-1];
            cost+=solve(i,idx-1,cuts,dp) + solve(idx+1,j,cuts,dp);
            mini=min(mini,cost);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(cuts.size()+1,vector<int>(cuts.size()+1,-1));
        return solve(1,cuts.size()-2,cuts,dp);
    }
};

