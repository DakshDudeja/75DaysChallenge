// { Driver Code Starts
// C++ implementation of For each element in 1st 
// array count elements less than or equal to it
// in 2nd array
#include <bits/stdc++.h>
 
using namespace std;


 // } Driver Code Ends
// function to count for each element in 1st array,
// elements less than or equal to it in 2nd array
class Solution{
  public:
  //bs on arr2
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], 
                                 int m, int n)
    {
    sort(arr2,arr2+n);
    vector<int>ans;
    for(int i=0;i<m;i++){
        int l=0,r=n-1,mid;
      while(l<=r){
           mid=l+(r-l)/2;
          if(arr2[mid]<=arr1[i]){
              l=mid+1;
          }
          else r=mid-1;
      }
        ans.push_back(l);
    }
    
    return ans;
  }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        int arr1[m],arr2[n];
        for(int i=0;i<m;i++)
        cin>>arr1[i];
        for(int j=0;j<n;j++)
        cin>>arr2[j];
        Solution obj;
        vector <int> res = obj.countEleLessThanOrEqual(arr1, arr2, m, n);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends