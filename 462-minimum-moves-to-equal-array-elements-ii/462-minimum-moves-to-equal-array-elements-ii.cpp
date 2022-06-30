class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int median=0;
        int n=nums.size();
        if(n==0) return 0;
        if(n%2==0){
            median = (nums[n/2-1]+nums[n/2])/2;
        }
        else 
            median = nums[n/2];
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+= abs(nums[i]-median);
        }
        return ans;
    }
};
