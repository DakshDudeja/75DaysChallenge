class Solution {
private:
    vector<vector<int>> ans;
    void solve(int i,vector<int> &nums,vector<int> &temp){
        if(i == nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(i+1,nums,temp);
        temp.pop_back();
        solve(i+1,nums,temp);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(),nums.end());
        solve(0,nums,temp);
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};