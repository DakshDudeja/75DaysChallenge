class Solution {
public:
    vector<int>arr={1,2,3,4,5,6,7,8,9};
    vector<string>res;
    set<int>st;
    void solve(int idx,string pat,string rsf,int prev){
        if(idx==pat.size()){
            res.push_back(rsf);
            return;
        }
        for(int i=0;i<arr.size();i++){
            if(!st.count(arr[i])){
                st.insert(arr[i]);
                if(pat[idx]=='I' and arr[i]>prev){
                    solve(idx+1,pat,rsf+to_string(arr[i]),arr[i]);
                }
                else if(pat[idx]=='D' and arr[i]<prev){
                    solve(idx+1,pat,rsf+to_string(arr[i]),arr[i]);
                }
                st.erase(arr[i]);
            }
        }
        return;
    }
    string smallestNumber(string pattern) {
        for(int i=0;i<arr.size();i++){
            st.insert(arr[i]);
            solve(0,pattern,to_string(arr[i]),arr[i]);
            st.erase(arr[i]);
        }
        sort(res.begin(),res.end());
        return res[0];
    }
};