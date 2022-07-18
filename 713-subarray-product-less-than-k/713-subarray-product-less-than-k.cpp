class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int prod=1,left=0,right=0,ans=0;
        while(right < nums.size()){
            prod=prod*nums[right];
            
            while(prod>=k){
                prod=prod/nums[left];
                left++;
            }
            ans+=right-left+1;
            right++;
        }
        if(ans<0) return 0;
        return ans;
    }
};