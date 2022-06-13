// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int solve(int idx,int n,int coins[],int target,vector<vector<int>>&dp){
	    if(idx>=n)return 1000000;
	    if(target==0)return 0;    
	    if(dp[idx][target]!=-1) return dp[idx][target];
	    
	    int consider=1000000;
        if(target - coins[idx] >=0){
             consider = 1 + solve(idx,n,coins,target-coins[idx],dp);
        }
        
         int notConsider = solve(idx+1,n,coins,target,dp);
        
	    return dp[idx][target]=min(consider,notConsider);
	    
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<vector<int>>dp(M+1,vector<int>(V+1,-1));
	   long long ans= solve(0,M,coins,V,dp);
	   if(ans==1000000)return-1;
	   else
	   return ans;
	} 
	
	
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends