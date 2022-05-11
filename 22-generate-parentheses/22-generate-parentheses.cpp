class Solution {
public:
    vector<string>res;
    void solve(int n,int open,int close,string temp,int maxi){
        if(temp.size()==maxi*2){
            res.push_back(temp);
            return;
        }
        if(open<maxi){
            solve(n,open+1,close,temp+'(',maxi);
        }
        if(close<open){
            solve(n,open,close+1,temp+')',maxi);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        solve(n,0,0,"",n);
        return res;
    }
};