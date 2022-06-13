// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int n)
    {
    vector<int>curr={ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        vector<int>res;
        for(int i=9;i>=0;i--){
            if(curr[i]>n)continue;
            else{
                int a=n/curr[i];
                n=n%curr[i];
                while(a--){
                    res.push_back(curr[i]);
                }
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends