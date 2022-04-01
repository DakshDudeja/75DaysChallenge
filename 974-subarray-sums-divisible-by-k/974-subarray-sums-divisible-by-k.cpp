class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;            //zero is occuring 1 time in array to handle all the corner cases
        int preSum=0,count=0;                        //prefix sum
        for(int i=0;i<nums.size();i++){
            preSum=preSum+nums[i];
            preSum=(preSum%k+k)%k;
            
            if(mp.find(preSum)!=mp.end()){
                count=count+mp[preSum];
                mp[preSum]+=1;
            }
            else
                mp[preSum] = 1;
        }
        return count;
    }
};