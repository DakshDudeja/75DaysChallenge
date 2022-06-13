// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
class Solution 
{
    public:
    bool static comp(Job A ,Job B)
   {
       return( A.profit>B.profit);
   }

    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,comp);
        int max_deadline=0;
        for(int i=0;i<n;i++){
            max_deadline=max(max_deadline,arr[i].dead);
        }
        vector<int>job_slot(max_deadline+1,-1);
        int profit=0,job_cnt=0;
        
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>0;j--){
                if(job_slot[j]==-1){
                    job_slot[j]=i;
                    profit+=arr[i].profit;
                    job_cnt++;
                    break;
                }
            }
        }
        vector<int>res;
        res.push_back(job_cnt);
        res.push_back(profit);
        
        return res;
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends