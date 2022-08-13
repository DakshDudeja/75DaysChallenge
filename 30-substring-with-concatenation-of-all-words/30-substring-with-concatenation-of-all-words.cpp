class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
    
        
        vector<int>res;
        unordered_map<string,int>mp;
        
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        int k=words[0].size();
        unordered_map<string,int>mp2=mp;
        if(s.size()< k*words.size()) return res;
        
        int i=0,j=0;
        while(j<s.size()){
            string t=s.substr(j,k);
            while(i<s.size() and mp.find(t)!=mp.end()){
                mp[t]--;
                if(mp[t]==0) mp.erase(t);
                if(mp.empty()) res.push_back(j);
                i+=k;
                t=s.substr(i,k);
            }
            mp=mp2;
            
            j++;
            i=j;
            if(s.size()-j < k*words.size()) break;
            
        }
        return res;
    }
};