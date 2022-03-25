class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int sumTillNow=0;
        for(int i=0;i<nums.size();i++){
            sum-=nums[i];
            if(sum==sumTillNow)
                return i;
            sumTillNow+=nums[i];

        }
        return -1;
    }
};