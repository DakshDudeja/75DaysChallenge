class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int streak=0;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]-1)==mp.end()){
                int curr=nums[i],temp=1;
                while(mp.find(curr+1)!=mp.end()){
                    temp++;
                    curr=curr+1;
                }
                streak=max(streak,temp);
            }
        }
        return streak;
    }
};
