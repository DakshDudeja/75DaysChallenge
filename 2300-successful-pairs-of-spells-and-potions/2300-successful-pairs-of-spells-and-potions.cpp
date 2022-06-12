class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long success) {
        sort(p.begin(),p.end());
        vector<int>res;
        for(int i=0;i<s.size();i++){
            long long t=s[i];
            long long s=0,e=p.size()-1,mid;
            int idx=-1;
            while(s<=e){
                 mid= s+(e-s)/2;
                long long x= t*1LL*p[mid];
                if(x>=success){
                    idx=mid;
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
             if(idx == -1) res.push_back(0);
            else res.push_back(p.size() - idx);
        }
        return res;
    }
};