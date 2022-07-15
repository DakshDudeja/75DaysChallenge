class Solution {
public:
    string solve(int &i,int n,string &s){
        string result;
        while(i<n and s[i]!=']'){
            if(isdigit(s[i])){
                int k=0;
                while(i<n and isdigit(s[i])){
                    k= k*10 + s[i++]-'0';
                }
                i++; //opening bracket
                string r =solve(i,n,s);
                while(k-- >0){
                    result+=r;
                }
                i++; //closing bracket
            }
            else{
                result+=s[i++];
            }
        }
        return result;
    }

    string decodeString(string s) {
        int i=0;
       return solve(i,s.size(),s);
    }
};