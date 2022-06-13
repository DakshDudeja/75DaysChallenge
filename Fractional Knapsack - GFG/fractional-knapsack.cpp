// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double,int>>h(n);
        for(int i=0;i<n;i++){
            h[i].first=(double)arr[i].value/arr[i].weight;      
            h[i].second=arr[i].weight;
        }
        sort(h.begin(),h.end());
        double ans=0;
        int j=n-1;
        while(W>0){
           ans+=h[j].first*h[j].second;
           W=W-h[j].second;
           j--;
        }
        j++;
        ans-=h[j].first*h[j].second;
        W=W+h[j].second;
        ans+=h[j].first*W;
        W=0;
        return ans;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends