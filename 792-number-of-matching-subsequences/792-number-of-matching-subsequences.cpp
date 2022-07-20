class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        unordered_map <string, int>map;
        for(int i=0; i<words.size(); i++){
            map[words[i]]++;
        }
        for(auto w = map.begin(); w!= map.end(); w++){
            int i=0, j=0;
            string word = w->first;
            while(i<s.length() && j<word.length()){
                if(s[i]==word[j]){
                    i++;
                    j++;
                }
                else{
                    i++;
                }
            }
            if(j==word.length()) ans += w->second;
        }
        return ans;
    }
};
