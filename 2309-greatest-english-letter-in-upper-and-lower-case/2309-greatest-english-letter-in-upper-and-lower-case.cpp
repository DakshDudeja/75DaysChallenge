class Solution {
public:
    string greatestLetter(string s) {
        string res="",ans="";
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)mp[s[i]]++;
        // for(auto it:mp)cout<<it.first<<endl;
        for(int i=0;i<s.size();i++){
            if(mp.find(tolower(s[i]))!=mp.end() and mp.find(toupper(s[i]))!=mp.end())
                res+=toupper(s[i]);
            else
                continue;
        }
        sort(res.begin(),res.end());
        if(res.size()==0)return res;
        else{
            ans+=res[res.size()-1];
        }
        return ans;
    }
};