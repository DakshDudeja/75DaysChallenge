class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        int r=matrix.size(),c=matrix[0].size();
        int m=0,n=0,k=r-1,l=c-1;
        int total=r*c,count=0;
        while(count<total){
            for(int i=m,j=n;j<=l and count<total ;j++){
                res.push_back(matrix[i][j]);
                count++;
            }
            m++;
            for(int i=m,j=l;i<=k and count<total;i++){
                res.push_back(matrix[i][j]);
                count++;
            }
            l--;
            for(int j=l,i=k;j>=n and count<total;j--){
                res.push_back(matrix[i][j]);
                count++;
            }
            k--;
            for(int i=k,j=n;i>=m and count<total;i--){
                res.push_back(matrix[i][j]);
                count++;
            }
            n++;
        }
        return res;
    }
};