class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int i=0;
        while(i<s.length()){
            if(s[i]=='(' or s[i]=='{' or s[i]=='[') {
                st.push(s[i]);
                i++;    
            }
      else {
            if(st.empty() || (st.top()=='(' and s[i]!=')') or (st.top()=='[' and s[i]!=']') or                                                   (st.top()=='{' and s[i]!='}')) return false;
                st.pop();
                i++;
            }
        }
         return st.empty();
    }
};