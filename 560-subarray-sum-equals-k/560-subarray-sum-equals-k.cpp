class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        m[0]++;
        int count=0,curr_sum=0;
        for(int i=0;i<nums.size();i++){
            curr_sum=curr_sum+nums[i];
            if(m.find(curr_sum-k)!=m.end()){
                count=count+m[curr_sum-k];
            }
            m[curr_sum]++;
        }
        return count;
    }
};