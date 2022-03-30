class Solution {
public:
    vector<int>temp;
    vector<vector<int>>res;
    void solve(int idx,vector<int>& c, int target){
        if(target==0){
            res.push_back(temp);
            return;
        }
        if(idx>=c.size()) return;
        if(c[idx]<=target){
            temp.push_back(c[idx]);
            solve(idx,c,target-c[idx]);
            temp.pop_back();        
        }
        solve(idx+1,c,target);
        return;
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        solve(0,c,target);
        return res;
        
    }
};