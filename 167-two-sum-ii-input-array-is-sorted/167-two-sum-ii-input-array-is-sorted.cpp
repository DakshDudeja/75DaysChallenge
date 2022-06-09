class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0,j=n-1;
        vector<int>res;
        while(i<j){
            if(nums[i]+nums[j]==target){
                res.push_back(i+1);
                res.push_back(j+1);
            }
            if(nums[i]+nums[j]>target){
                j--;
            }
            else{
                i++;
            }
        }
        return res;
    }
};