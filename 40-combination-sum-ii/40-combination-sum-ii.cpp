class Solution {
public:
   vector<vector<int>>res;
    void solve(int i,vector<int>temp,vector<int>&c,int target){
        if(target==0){
            res.push_back(temp);
            return;     
        }
        if(i>=c.size() )return;
        
        if(c[i]<=target){
            temp.push_back(c[i]);
            solve(i+1,temp,c,target-c[i]);
            temp.pop_back();
        }
        while(i+1 < c.size() and c[i] == c[i+1]) i++;
        solve(i+1,temp,c,target);
        
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        vector<int>temp;
        sort(c.begin(),c.end());
        solve(0,temp,c,target);
        return res;
    }
};