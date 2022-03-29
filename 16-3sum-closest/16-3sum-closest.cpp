class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int temp=INT_MAX;
        int res=0;
        for(int i=0;i<nums.size();i++){
            int l=i+1,r=nums.size()-1;
            while(l<r){
                int mid= nums[l]+nums[r]+nums[i];
                if(mid==target)return mid;
                
                if(abs(target-mid) < temp){
                    temp = abs(target-mid);
                    res=mid;
                }
                if(mid > target)
                    r--;
                else 
                   l++;
            }
        }
        return res;
    }
};