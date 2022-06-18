class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        unordered_map<int,int>mp;
        for(int i=0;i<nums2.size();i++) mp[nums2[i]]=i;
        for(int i=0;i<nums1.size();i++){
            int f=nums1[i];
            if(mp.find(f)==mp.end()) {
                res.push_back(-1);
                continue;
            }
            int flag=0;
            for(int j=mp[f];j<nums2.size();j++){
                if(nums2[j]>f){
                    flag=1;
                    res.push_back(nums2[j]);
                    break;
                }
            }
            if(flag==0)res.push_back(-1);
            
        }
        return res;
    }
};