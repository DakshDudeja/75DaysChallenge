class Solution {
public:
    int side_sum;
    bool solve(vector<int>& nums,int sum,int idx,int cnt,int n,vector<bool>& visited){
        
        if(cnt==4){
            return true;
        }    
        
        if(sum == 0) return solve(nums,side_sum,0,cnt+1,n,visited);
        
        for(int i=idx;i<nums.size();i++){
            
            if(sum-nums[i]>=0 && !visited[i]){
                visited[i]=true;
            
                if(solve(nums,sum-nums[i],i+1,cnt,n+1,visited)) return true;
            
                visited[i]=false;
            }
            
        }
    
        return false;
    }
    bool makesquare(vector<int>& matchsticks) 
    {
        int sum=0;
        for(int i=0;i<matchsticks.size();i++){
            sum += matchsticks[i];
        }
        
        vector<bool> visited(matchsticks.size());
        
        if(sum%4==0&&matchsticks.size()>=4){
            side_sum=sum/4;
            return solve(matchsticks,side_sum,0,0,0,visited);
        }
        else
            return false;
    }
};