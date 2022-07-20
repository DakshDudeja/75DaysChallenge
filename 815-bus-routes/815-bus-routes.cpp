class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n=routes.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<routes[i].size();j++){
                mp[routes[i][j]].push_back(i);
            }
        }
        // vector<vector<int>>visBusno(n,vector<int>(m,false));
        // vector<int>visBustop(n,false);
        set<int>busVis;
        set<int>bustopVis;
        queue<int>q;
        q.push(source);
        bustopVis.insert(source);
        int level=0;
        
        while(!q.empty()){
            int size=q.size();
            while(size-- >0){
                int currBus=q.front();
                q.pop();
                
                if(currBus == target) return level;
                
                for(auto it:mp[currBus]){
                    if(busVis.count(it)) continue;
                    else
                        busVis.insert(it);
                    for(auto e:routes[it]){
                        if(bustopVis.count(e))continue;
                        else{
                            bustopVis.insert(e);
                            q.push(e);
                        }
                            
                    }
                }
            }
            level++;
        }
        return -1;
    }
};