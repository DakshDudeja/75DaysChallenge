class Solution {
public:
    bool isValid(string s) {
        int i=0;
        stack<char>st;
        while(i<s.size()){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{') st.push(s[i]),i++;
            else if(st.size() and s[i]==')' and st.top()=='(') st.pop(),i++;
            else if(st.size() and s[i]==']' and st.top()=='[') st.pop(),i++;
            else if(st.size() and s[i]=='}' and st.top()=='{') st.pop(),i++;
            else{
               return false;
            }
        }
    
        return !st.size();
    }
};