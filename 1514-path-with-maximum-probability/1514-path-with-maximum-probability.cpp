class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {

        vector<vector<pair<int,double>>>graph(n);
        // int c=0;
        for(int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});   
        }

        // for(auto it:edges){
        //     int u=it[0];
        //     int v=it[1];
        //     int cost = succProb[c];
        //     graph[u].push_back(make_pair(v,cost));
        //     c++;
        // }
        vector<double>cost(n,0);
        
        if(graph[start].size()==0) return 0;
        priority_queue<pair<double,int>>pq;
        
        cost[start]=1;
        
        pq.push(make_pair(1.0,start));
        while(!pq.empty()){
            int currVertex = pq.top().second;
            double currCost = pq.top().first;
            pq.pop();
            
            for(auto nbr:graph[currVertex]){
                
                if(currCost * nbr.second > cost[nbr.first]){
                    cost[nbr.first] = currCost * nbr.second;
                    pq.push(make_pair(cost[nbr.first], nbr.first));

                }
            }
        }
            return cost[end];
    }
};