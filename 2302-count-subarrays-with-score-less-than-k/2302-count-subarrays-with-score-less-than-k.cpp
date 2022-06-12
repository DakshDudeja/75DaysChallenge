class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        long long int j=0,sum=0,ans=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum*(i-j+1)>=k){
                sum-=nums[j];
                j++;
            }
            ans+=(i-j+1);
        }
        return ans;
    }
};