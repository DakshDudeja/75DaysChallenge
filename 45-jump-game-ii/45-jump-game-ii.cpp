class Solution {
public:
   int solve(int currIdx,vector<int>&nums,vector<int>&dp){      //this is a greedy approach problem                                                                              becoz of time constraints 
                                                                    //solve it in o(n)
        if(currIdx>=nums.size()-1) return 0;
        
        int currentJump = nums[currIdx];
        
        if(dp[currIdx]!=-1) return dp[currIdx];
        int ans = 10001;
        
        for(int i=1;i<=currentJump;i++){
            int tempAns = 1+ solve(i+currIdx,nums,dp);
            ans = min(ans,tempAns);
        }
        return dp[currIdx] = ans;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return solve(0,nums,dp);
    }
};