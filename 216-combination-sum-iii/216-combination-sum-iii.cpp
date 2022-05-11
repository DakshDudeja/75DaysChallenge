class Solution {
public:
    vector<vector<int>>res;    
    void solve(int k,int target,int currSum,int i,vector<int>&ans){
        
        if(target < 0 || ans.size() > k) return ;
        if(ans.size()==k and target==0 ){            
            res.push_back(ans);
            return ;
        }
        
        //cout<<i<<" "<<currSum<<" "<<target<<endl;
        
        for(int idx=i;idx<=9; idx++){
                ans.push_back(idx);
                solve(k,target-idx,currSum+idx,idx+1,ans);
                ans.pop_back();
        }
        return ;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>ans;
        solve(k,n,0,1,ans);
        return res;
    }
};