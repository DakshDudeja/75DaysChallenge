class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n);
        vector<int>right(n);
        int prod=1,lefti=INT_MIN;
        for(int i=0;i<n;i++){
            prod*=nums[i];
            left[i]=prod;
            lefti=max(lefti,left[i]);
            if(prod==0) prod=1;
        }
        prod=1;
        int righti=INT_MIN;
        for(int i=n-1;i>=0;i--){
            prod*=nums[i];
            right[i]=prod;
            righti=max(righti,right[i]);
            if(prod==0) prod=1;
        } 
        return max(lefti,righti); 
    }
};