class Solution {
public:
    int maxi=0;
    void expand_around_center(int i,int j,string &s,string &res){
        while(i>=0 and j<s.size() and s[i]==s[j]){
            i--,j++;
        }
        i++,j--;  //to avoid overflow
        int len=j-i+1;
        if(len>maxi){
            res=s.substr(i,j-i+1);
            maxi=len;
        }
        
    }
    string longestPalindrome(string s) {
         string res;
        for(int i=0;i<s.size();i++){
            expand_around_center(i-1,i,s,res); //even
            expand_around_center(i-1,i+1,s,res); //odd
            
        }
        return res;
    }
};