class Solution {
public:
    map<string,string>mp;
    int nums=0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        nums++;
        string ans="http://tinyurl.com/";
        ans+=to_string(nums);
        mp[ans]=longUrl;
        return ans;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));