class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>graph(n,vector<int>(n,0));
        int r=n,c=n;
        int p=0,l=0,m=n-1,k=n-1;
        int total=r*c,count=0;
        while(count<total){
            for(int i=p,j=l;j<=m and count<total ;j++){
                graph[i][j]=count+1;
                count++;
            }
            p++;
            for(int i=p,j=m;i<=k and count<total; i++){
                graph[i][j]=count+1;
                count++;
            }
            m--;
            for(int i=k,j=m;j>=l and count<total;j--){
                graph[i][j]=count+1;
                count++;
            }
            k--;
            for(int i=k,j=l;i>=p and count<total;i--){
                graph[i][j]=count+1;
                count++;
            }
            l++;
        }
        return graph;
    }
};