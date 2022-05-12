class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int>leftprod(n);
        vector<int>rightprod(n);
        int leftmax=INT_MIN ,rightmax=INT_MIN;
        int prod=1;
        for(int i=0;i<n;i++){
            prod*=nums[i];
            leftprod[i]=prod;
            leftmax=max(leftmax,leftprod[i]);
            
            if(prod==0) prod=1;
        }
        prod=1;
        for(int i=n-1;i>=0;i--){
            prod*=nums[i];
            rightprod[i]=prod;
            rightmax=max(rightmax,rightprod[i]);
            
            if(prod==0) prod=1;
        }
        return max(leftmax,rightmax);
    }
};