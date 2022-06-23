class Solution {
public:
    bool isAnagram(string s, string t) {
        
        vector<int> arr(26);
        
        for(auto &it : s) arr[it - 'a']++;
        
        for(auto &it : t) arr[it - 'a']--;
        
        for(auto &it : arr) if(it) return false;
        
        return true;
    }
};
