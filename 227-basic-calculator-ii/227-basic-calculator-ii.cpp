class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        s+='+';
        long long int ans=0,curr=0;
        char sign='+';
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])) 
                curr=curr*10 + (s[i]-'0');
            else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
                      if(sign=='+') st.push(curr);
                      else if(sign=='-') st.push((-1)*curr);
                      else if(sign=='*'){
                        int t=st.top();
                        st.pop();
                        st.push(curr*t);
                      }
                      else if(sign=='/'){
                         int t=st.top();
                         st.pop();
                         st.push(t/curr);
                    }
                    curr=0;
                    sign=s[i];
            }
          }       
       
        while(st.size()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};