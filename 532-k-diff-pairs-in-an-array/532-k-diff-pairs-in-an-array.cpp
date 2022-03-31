class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
                int cnt=0;

        if(k==0){
            for(auto it:mp){
                if(it.second>1) cnt++;
                }
        return cnt;
        }
        for(auto it:mp){
            if(mp.count(it.first+k)>0 ){
                cnt++;
            }
        }
        return cnt;
    }
};