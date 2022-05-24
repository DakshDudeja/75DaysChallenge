class Solution {
public:
    int dp[301];
    bool solve(int idx,string &s,unordered_set<string> &st){
        if(idx >= s.size()) return true;
        else if(dp[idx] != -1) return dp[idx];
        
        string temp;
        for(int i=idx;i<s.size();i++){
            temp += s[i];
            if(st.find(temp) != st.end()){
                if(solve(i+1,s,st)) return true;
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto &it : wordDict) st.insert(it);
        memset(dp,-1,sizeof dp);
        return solve(0,s,st);
    }
};
