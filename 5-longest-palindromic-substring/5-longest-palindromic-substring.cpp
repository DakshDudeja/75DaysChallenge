class Solution {
    void expand_around_center(string &str,int l,int r,string &ans){
        while(l >= 0 and r < str.size() and str[l] == str[r]){
            l--,r++;   
        }
        l++,r--;  //to avoid overflow
        string temp = str.substr(l,r-l+1); //l-r+1 = length of substring
        // cout<<temp<<endl;
        if(temp.size() > ans.size()) ans = temp;
    }
public:
    string longestPalindrome(string str) {
        int n = str.size();
        string ans;
        for(int i=0;i<n;i++){
            expand_around_center(str,i-1,i+1,ans); // odd length palindrome
            expand_around_center(str,i-1,i,ans); // even length palindrome
        }
        return ans;
    }
};