class Solution {
public:
     vector<vector<int>>res;
    void solve(int i,vector<int>&s,int n){
        if(i==n){
            res.push_back(s);
        }
        for(int j=i;j<n;j++){
            swap(s[j],s[i]);
            solve(i+1,s,n);
            swap(s[j],s[i]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n =nums.size();
        solve(0,nums,n);
        return res;
    }
};