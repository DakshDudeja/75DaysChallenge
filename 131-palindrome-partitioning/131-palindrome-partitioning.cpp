class Solution {
public:
    vector<vector<string>>res;    
    bool isPalindrome(int i,int j,string s){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++,j--;
        }
        return true;
    }
    void solve(int idx,string s,vector<string>&temp){
        if(idx>=s.length()){
            res.push_back(temp);
            return;
        }
        for(int j=idx;j<s.length();j++){
            if(isPalindrome(idx,j,s)){
                temp.push_back(s.substr(idx,j-idx+1));
                solve(j+1,s,temp); //agar substring jayada bada hai to i+1 ki jagah j+1 hoga vrn                                               duplicate answers ayege
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        solve(0,s,temp);
        return res;
    }
};
