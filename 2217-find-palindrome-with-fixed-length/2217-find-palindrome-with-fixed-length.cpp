class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int length) {
        vector<long long>res;
        int power=0;
        if(length%2==0)
             power=length/2-1;
        else
             power=length/2;
        int start= pow(10,power);
        
            for(int i=0;i<queries.size();i++){
                string ans= to_string(start+queries[i]-1);
                string t=ans;
                reverse(t.begin(),t.end());
               
                if(length%2==0)
                        ans=ans+t;
                else{
                    ans=ans+t.substr(1,t.size()-1);
                }
                if(ans.size()==length)
                res.push_back(stoll(ans));
                else
                    res.push_back(-1);
            }
        return res;
    }
};