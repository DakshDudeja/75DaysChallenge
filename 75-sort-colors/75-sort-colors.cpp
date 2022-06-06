class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size()<=1)return;
        int cnt=0,cnt1=0,cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)cnt++;
            else if(nums[i]==1)cnt1++;
            else
                cnt2++;
        }
        int i=0;
        while(cnt and i<nums.size()){
            nums[i]=0;
             cnt--;        
            i++;
        }
        while(cnt1){
            nums[i]=1;
            i++;
            cnt1--;
        }
        while(cnt2){
            nums[i]=2;
            i++;
            cnt2--;
        }
    }
};