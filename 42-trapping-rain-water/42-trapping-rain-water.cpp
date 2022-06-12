class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        int left=0,right=n-1,res=0;
        int maxLeft=0,maxRight=0;
        while(left<right){
            if(h[left]<=h[right]){
                if(h[left]>=maxLeft) maxLeft=h[left];
                else
                    res+=maxLeft-h[left];
                left++;
            }
            else{
                if(h[right]>maxRight) maxRight = h[right];
                else
                    res+=maxRight-h[right];
                right--;
            }
        }
        return res;
    }
};