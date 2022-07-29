class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        
        int n=h.size(),m=h[0].size();
        priority_queue<vector<int>>pq;
        pq.push({0,0,0});
        
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        
        vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
        while(pq.size()){
            auto currNode = pq.top();
            pq.pop();
            
            int currWt = -currNode[0];
            int currR =  currNode[1];
            int currC =  currNode[2];
            
            if(currR==n-1 and currC==m-1) return currWt;
            
            for(auto it:dir){
                int i=currR + it[0];
                int j=currC + it[1];
                
                if(i>=0 and i<n and j>=0 and j<m ){
                    int neuWt = max(currWt, abs(h[currR][currC] - h[i][j]));
                    if(dist[i][j]>neuWt){
                        dist[i][j]=neuWt;
                        pq.push({-neuWt,i,j});

                    }
                    
                }
            }
            
        }
        return -1;
    }
};