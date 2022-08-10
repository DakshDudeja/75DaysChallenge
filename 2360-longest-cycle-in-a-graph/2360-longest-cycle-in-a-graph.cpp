class Solution {
public:
    void bfs(int src, vector<int>& edges, unordered_map<int, pair<int, int>> &vis, int &res)
    {
        queue<pair<int, int>> q;
        q.push({1 , src});
        vis[src] = {1, src};
        
        while(!q.empty())
        {
            int len = q.front().first;
            int node = q.front().second;
            q.pop();
            
            if(edges[node] != -1)
            {
                if(vis.find(edges[node]) == vis.end())      //If node is not visited mark it as visited
                {                                           //and increase its length
                    vis[edges[node]] = {len+1, src};
                    q.push({len+1, edges[node]});
                }
                else if(vis[edges[node]].second == src)        //if the node is visited then check if it is
                {                                               //visited in current traversal or not
                    res = len - vis[edges[node]].first + 1;    //if it is visited in current traversal then only
                }                                               
            }
        }
       
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        int ans = -1;
        unordered_map<int, pair<int, int>> vis; //In visited i am storing length till current node from source
                                                //and source of the traversal
        for(int i=0; i<n; i++)
        {   
            int res = -1;
            bfs(i, edges, vis, res);
            ans = max(res, ans);
        }
        return ans;
    }
};
