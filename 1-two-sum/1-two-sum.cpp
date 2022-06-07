class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i])!=mp.end() and i!=mp[target-nums[i]]){
                res.push_back(i);
                res.push_back(mp[target-nums[i]]);
                mp.erase(nums[i]);
                mp.erase(target-nums[i]);
            }
        }
        return res;
    }
};