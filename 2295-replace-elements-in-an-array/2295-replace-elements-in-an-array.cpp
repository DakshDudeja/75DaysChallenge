class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& op) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        for(int i=0;i<op.size();i++){
           int t=mp[op[i][0]];
            mp.erase(op[i][0]);
            mp[op[i][1]]=t;
            nums[t]=op[i][1];
        }
        return nums;
    }
};
