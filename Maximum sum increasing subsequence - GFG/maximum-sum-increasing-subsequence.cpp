// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int dp[1001][1001];
	int solve(int i,int previ,int arr[],int n){
	   if(i >= n) return 0;
	   if(dp[i][previ+1]!=-1) return dp[i][previ+1];
	   int op1=0,op2=0;
	   if(previ==-1 || arr[i]>arr[previ]){
	       op1=arr[i]+solve(i+1,i,arr,n);
	   }
	   op2=solve(i+1,previ,arr,n);
	   return dp[i][previ+1]=max(op1,op2);
	}
	int maxSumIS(int arr[], int n){
	    memset(dp,-1,sizeof dp);
	    return solve(0,-1,arr,n);
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends