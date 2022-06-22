class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==' ')
                continue;
            int j=i;
            while(i>=0 && s[i]!=' '){
                i--;
            }
            ans+=s.substr(i+1,j-i)+" ";
        }
        if(ans.back()==' ')//to remove last space added
            ans.pop_back();
        return ans;
    }
};