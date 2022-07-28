class Solution {
public:
    int dp[101][101];
    int solve(int i,int j,int n,vector<int>&cuts){
        if(i>j) return 0;
        
        int mini=INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];

        for(int idx=i;idx<=j;idx++){
            int cost= cuts[j+1]-cuts[i-1];
            cost+= solve(i,idx-1,n,cuts) + solve(idx+1,j,n,cuts);
            mini=min(mini,cost);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(),cuts.end());
        return solve(1,cuts.size()-2,n,cuts);    
    }
};
