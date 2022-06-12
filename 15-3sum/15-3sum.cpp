class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i > 0 && nums[i]==nums[i-1])
                continue;
            int j=i+1,k=nums.size()-1;
            int x = nums[i];
            while(j<k){
                
                if(nums[j]+nums[k]+x > 0) 
                    k--;
                else if(nums[j]+nums[k]+x <0)
                    j++;
                else{
                    vector<int>temp;

                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    res.push_back(temp);
                    
                    while(j<k and nums[j]==temp[1])j++;
                    while(j<k and nums[k]==temp[2])k--;
                }
                
               
            }
        
        }
        return res;
    }
};