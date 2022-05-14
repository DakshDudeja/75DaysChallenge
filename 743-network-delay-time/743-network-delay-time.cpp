class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>graph(n+1);
        for(auto edge:times){
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];
            graph[u].push_back(make_pair(v,cost));
        }
        vector<bool>vis(n+1,false);
        vector<int>cost(n+1,INT_MAX);
        if(graph[k].size()==0) return -1;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        cost[k]=0;
        pq.push(make_pair(0,k));
        while(!pq.empty()){
            int currVertex = pq.top().second;
            int currCost = pq.top().first;
            pq.pop();
            if(vis[currVertex]) continue;
            
            cost[currVertex] = currCost;
            vis[currVertex] =true;
            for(auto nbr:graph[currVertex]){
                int currNbr = nbr.first;
                int currNbrCost = nbr.second;
                if(!vis[currNbr])
                    pq.push(make_pair(currCost+currNbrCost,currNbr));
            }
        }
        int answer = 0;
        for(int i = 1 ; i < cost.size() ; ++i){    
            answer = max(answer , cost[i]);    // Distance of farthest node would be our answer.
        }
        if(answer == INT_MAX){      // Means we have missed some node.
            return -1;
        }
        return answer;              
    }
};