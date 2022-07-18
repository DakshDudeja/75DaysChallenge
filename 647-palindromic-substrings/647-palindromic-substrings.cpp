class Solution {
public:
    int countSubstrings(string s) {
        int odd=0,even=0,n=s.size();
        for(int i=0;i<s.size();i++){
            
            int l=i,r=i;
            while(l>=0 and r<n and s[l]==s[r]){
                 l--,r++;
                 odd++;
            }
            
             l=i,r=i+1;
            while(l>=0 and r<n and s[l]==s[r]){
                even++;
                l--,r++;
            }
            
        }
        return odd+even;
    }
};