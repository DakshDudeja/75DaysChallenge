class Solution {
public:
    vector<vector<int>>res;
    void solve(int i,vector<int>temp,vector<int>&c,int target){
        if(target==0){
            res.push_back(temp);
            return;     
        }
        if(i>=c.size() || target <0)return;
        
        temp.push_back(c[i]);
        solve(i,temp,c,target-c[i]);
        temp.pop_back();

        solve(i+1,temp,c,target);
        
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        vector<int>temp;
        solve(0,temp,c,target);
        return res;
    }
};