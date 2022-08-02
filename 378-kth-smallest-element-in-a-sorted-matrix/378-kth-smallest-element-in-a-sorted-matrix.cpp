class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> > pq;
        int n=mat.size();
        for(int i=0; i<n; ++i)
            pq.push({mat[0][i],{0,i}});
        
        int ans;
        while(k--)
        {
            int val=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            ans=val;
            if(row!=n-1)
                pq.push({mat[row+1][col],{row+1,col}});
        }
        return ans;
    }
};
//Time - O(max(m,k)*log(min(m,k)) -- Priority-queue | C++


// 1 2 3       
// 1 3 6
// 1 8 9


//k=6
//row=2 
//col=0

//    2 3 




// 1  5  11 
// 10 11 13
// 12 13 15

// 1 5  11  10 11 13 12  13
// 1 5  10  11  11 12 13 13

// 1 2
// 1 3

//1 1 2 3


// 

