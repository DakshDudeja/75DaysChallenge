// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{ 
   int fun(vector<int>&arr,int sum,int n,vector<vector<int>>&dp,int i)
   {
       if(i >= n)return 0;
       if(sum < 0)return 0;
       if(dp[i][sum] != -1)return dp[i][sum];
       int a =0,b=0;
       if(sum - arr[i] >=0)
       {
           a = max(arr[i]+fun(arr,sum-arr[i],n,dp,i+1), fun(arr,sum,n,dp,i+1));
       }
       else
       b = fun(arr,sum,n,dp,i+1);
       
       return dp[i][sum] = max(a,b);
   }
public:
   bool isSubsetSum(vector<int>arr, int sum){
       // code here 
       int n = arr.size();
       vector<vector<int>>dp(n+1,vector<int>(sum+1, -1));
       int x = fun(arr,sum,n,dp,0);
       if(x == sum)return true;
       return false;
   }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends