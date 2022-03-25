class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
           pq.push({costs[i][0]-costs[i][1],i}); 
        }
        int cnt=0;
        while(pq.size()>n/2){
            int j=pq.top().second;
            cnt+=costs[j][1];
            pq.pop();
        }
        while(!pq.empty()){
            int j=pq.top().second;
            cnt+=costs[j][0];
            pq.pop();
        }
         return cnt;
    }
};