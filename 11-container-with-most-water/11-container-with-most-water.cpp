class Solution {
public:
    int maxArea(vector<int>& height) {
        int res=0,tempArea=0;
        int s=0,e=height.size()-1;
        while(s<=e){
            if(height[s]<=height[e]){
                tempArea=height[s]*(e-s);
                s++;
            }
            else if(height[s]>height[e]){
                tempArea=height[e]*(e-s);
                e--;                
            }
            res=max(res,tempArea);
        }
        return res;
    }
};