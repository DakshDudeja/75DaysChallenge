class Solution {
public:
    typedef long long ll;
    int setbits(int n){
        int cnt = 0;
        while(n){
            cnt += (n%2);
            n /= 2;
        }
        return cnt;
    }
    
    long long countExcellentPairs(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        vector<int> v;
        for(auto& i: s){
            int x = setbits(i);
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        
        ll ans = 0;
        for(int i=0;i<v.size();i++){
            int p = k-v[i];
            auto it = lower_bound(v.begin(),v.end(),p);
            ans += (v.end()-it);
        }
        return ans;
        
    }
};
