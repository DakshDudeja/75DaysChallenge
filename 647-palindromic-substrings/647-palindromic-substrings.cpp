class Solution {
public:
    int countSubstrings(string s) {
        int cnt=0;
        for(int i=0;i<s.size();i++){
                int b=i,e=i;
                while( b>=0 and e<s.size() and s[b]==s[e] ){ // for odd length palindromes
                     cnt++;
                     b--,e++;
                
            }
            
                int d=i,f=i+1;
                while(d>=0 and f<s.size() and s[d]==s[f]){  //for even length palindromes
                     cnt++;
                     d--,f++;
                }
            
        }
        return cnt;
    }
};