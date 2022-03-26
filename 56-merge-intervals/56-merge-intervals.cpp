class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         vector<vector<int>> res;
        
        if(intervals.size()==0)
            return res;
        sort(intervals.begin(), intervals.end());
        vector<int> temp=intervals[0];
        for(auto it:intervals){
            if(it[0]<=temp[1]){
                temp[1]=max(it[1],temp[1]);
                 //temp[0]=min(it[0],temp[0]);
            }
            else{
                res.push_back(temp);
                temp=it;
            }
        }
         res.push_back(temp);
        return res;
        
    }
};