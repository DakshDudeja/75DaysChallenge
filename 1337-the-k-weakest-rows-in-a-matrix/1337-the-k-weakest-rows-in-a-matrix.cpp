class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int>res;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<mat.size();i++){
            int cnt=0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1)cnt++;
            }
            pq.push(make_pair(cnt,i));
        }
        while(k--){
            int t=pq.top().second;
            res.push_back(t);
            pq.pop();
        }
        return res;
    }
};