class Solution {
private:
    unordered_set<int> st;
    unordered_map<int,int> mp;
    const int mod = 1e9 + 7;
    long long solve(int ele,vector<int> &arr){
        if(mp.count(ele)) return mp[ele];
        
        long long res = 1;
        for(auto &val : arr){
            if(ele % val == 0 and st.count(ele/val)){
                res = (res + ((solve(val,arr) * solve(ele/val,arr)) %mod)) % mod;
            }
        }
        
        return mp[ele] = res;
    }
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        st.insert(arr.begin(),arr.end());
        long long ans = 0;
        for(auto &ele : arr)
            ans = (ans + solve(ele,arr)) % mod;
        return ans % mod;
    }
};