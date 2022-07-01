class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return (a[1]>b[1]);
    } 
    int maximumUnits(vector<vector<int>>& b, int t) {
        sort(b.begin(),b.end(),comp);
        int sum=0;
        for(int i=0;i<b.size();i++){
            if(b[i][0]<=t){
                sum+=(b[i][0]*b[i][1]);
                t=t-b[i][0];
            }
            else{
                sum+=(t*b[i][1]);    
                t=0;
            } 
        }
        return sum;
    }
};