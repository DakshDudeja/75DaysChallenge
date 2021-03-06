class Solution {
public:
   int solve(long long i,string&s,long long k,long long lencount,long long t[1001][1001]){
        int n=s.size();
        if(i==n) return 0;
        if(k<0) return 0;
        
        if(t[i][lencount]!=-1) return t[i][lencount];
        int pick=0;
       if((long long)(s[i]-'0')*pow(2,lencount)<=k)
		 pick=1+solve(i+1,s , k-(long long)(s[i]-'0')*pow(2,lencount), lencount+1, t);
        
         int notpick = solve(i+1,s,k,lencount,t);
    		return t[i][lencount]=max(pick,notpick);

    }
    int longestSubsequence(string s, int k) {
        int n=s.size();
        reverse(s.begin(),s.end());
        long long t[1001][1001];
        memset(t,-1,sizeof(t));
        return solve(0,s,k,0,t);
        
    }
};