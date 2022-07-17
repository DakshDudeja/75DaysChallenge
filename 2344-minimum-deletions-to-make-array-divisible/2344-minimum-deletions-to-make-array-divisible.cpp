class Solution {
public:
    int gcd(int a, int b)
    {
      if (a == 0)
        return b;
      return gcd(b % a, a);
    }
    int minOperations(vector<int>& nums, vector<int>& arr) {
        
          int n=arr.size();
          int result = arr.front();
        sort(arr.begin(),arr.end());
          for (int i = 1; i < n; i++)
          {
            result = gcd(arr[i], result);
            if(result == 1)break;
          }
        // cout<<result;
          sort(nums.begin(),nums.end());
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=result and result%nums[i]==0) return i;
        }
        return -1;
    }
};