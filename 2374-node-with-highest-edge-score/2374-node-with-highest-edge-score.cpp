class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n=edges.size();
        vector<long long>indegree(n+1);
        unordered_map<long long,vector<long long>>mp;
        for(int i=0;i<edges.size();i++){
            mp[edges[i]].push_back(i);
        }
        long long maxi=0;
        for(auto it:mp){
            long long cnt=0;
            for(auto e:it.second){
                cnt+=e;
            }
            maxi=max(maxi,cnt);
            indegree[it.first]=cnt;
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==maxi) return i;
        }
        return 0;
    }
};