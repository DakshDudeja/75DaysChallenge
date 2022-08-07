class Solution {
public:
    int longestIdealString(string s, int k) {
        map<char,long long int>mp;
        mp[s[0]]=1;
        long long int ans=1;
        for(int i=1;i<s.size();i++){
            
            long long int best=1;
            for(auto it:mp){
                if(abs(it.first-s[i])<=k){
                    best=max(best,it.second+1);
                }
            }
            mp[s[i]]=best;
            ans=max(ans,best);
            
        }
        return ans;
    }
};