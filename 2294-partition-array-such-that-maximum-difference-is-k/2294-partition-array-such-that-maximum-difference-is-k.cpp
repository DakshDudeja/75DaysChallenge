class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        int j=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]-j>k){
                cnt++;
                j=nums[i];
            }
        }
        return cnt+1;
    }
};