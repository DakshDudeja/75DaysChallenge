class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int k=0;
        for(int i=0;i<nums.size();i++){
            k+=nums[i];
        }
        k-=x;
        if(k==0)return nums.size();
        if(k<0)return -1;
        int sum=0,maxlen=0;               //prefix sum approach to calculate longest subarray of target k
        int j=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k){
                maxlen=max(maxlen,i-j+1);
            }
            else if(sum>k){
                while(sum>k){
                    sum-=nums[j];
                    j++;
                }
                if(sum == k){
                     maxlen = max(maxlen, i-j+1);
                 }
            }
            
        }
        if(maxlen==0)return -1;
        else
        return nums.size()-maxlen;
        
    }
};