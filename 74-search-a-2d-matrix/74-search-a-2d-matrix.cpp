class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n=matrix.size(),m=matrix[0].size();
          if(n == 0 || m == 0)
            return false;
        int start=0,end=(m*n)-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            int sr=mid/m,sc=mid%m;
            if(matrix[sr][sc]==target)return true;
            if(matrix[sr][sc]<target) 
                start=mid+1;
            else
                end=mid-1;
        }
        return false;
    
    }
};