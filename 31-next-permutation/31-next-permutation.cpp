class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int bp=-1;
        int n=nums.size();   //algorithm to find next permutation lexicographically
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                bp=i;
                break;   
            }
        }
        if(bp<0){
            reverse(nums.begin(),nums.end());
            return;
        }
        int bp2=-1;
        for(int i=n-1;i>=0;i--){
            if(nums[bp]<nums[i]){
                bp2=i;
                break;
            }
        }
        swap(nums[bp],nums[bp2]);
        reverse(nums.begin() + bp + 1, nums.end());
    }
};