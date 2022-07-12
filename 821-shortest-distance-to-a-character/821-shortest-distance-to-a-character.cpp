class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int>cnt;
        for(int i=0;i<s.size();i++) if(s[i]==c) cnt.push_back(i);
        
        vector<int>ans;
        int t=0;
        for(int i=0;i<s.size();i++){
            int a=abs(i-cnt[t]);
            int b=INT_MAX;
            if(t+1<cnt.size())
                b=abs(i-cnt[t+1]);
            if(a<b)
                ans.push_back(a);
            else{
                ans.push_back(b);
                t++;
            }
        }
        return ans;
    }
};