class Solution {
public:
    int solveLeft(vector<int>& nums, int target){
        int l=0,h=nums.size()-1;
        int res=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]==target)res=mid;
            if(nums[mid]>=target){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return res;
    }
    int solveRight(vector<int>& nums, int target){
        int l=0,h=nums.size()-1;
        int res=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]==target)res=mid;
            if(nums[mid]<=target){
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        ans.push_back(solveLeft(nums,target));
        ans.push_back(solveRight(nums,target));
        return ans;
    }
};