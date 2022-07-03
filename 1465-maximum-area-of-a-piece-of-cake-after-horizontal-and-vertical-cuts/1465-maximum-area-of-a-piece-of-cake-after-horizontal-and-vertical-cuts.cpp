class Solution {
public:
    int maxArea(int row, int col, vector<int>& h, vector<int>& v) {
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        int maxi=0,maxi2=0;
        for(int i=1;i<h.size();i++){
            maxi=max(maxi,h[i]-h[i-1]);
        }
        maxi=max(maxi,h[0]);
        maxi=max(maxi,abs(h[h.size()-1]-row));
         
        for(int i=1;i<v.size();i++){
            maxi2=max(maxi2,v[i]-v[i-1]);
        }
        maxi2=max(maxi2,v[0]);
        maxi2=max(maxi2,abs(v[v.size()-1]-col));
        
        return (1LL*maxi*maxi2)%1000000007;
    }
};