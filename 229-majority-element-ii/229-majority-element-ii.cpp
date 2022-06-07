class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int m1=-1,m2=-1;   //obervation -  maximum 2 elements can be in answer
        int cnt1=0,cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(m1==nums[i])cnt1++;
            else if(m2==nums[i])cnt2++;
            else if(cnt1==0){
                m1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0){
                m2=nums[i];
                cnt2=1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int>res;
        cnt1=0,cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==m1)cnt1++;
            else if(nums[i]==m2)cnt2++;
        }
        int n=nums.size();
        if(cnt1>n/3)
        res.push_back(m1);
        if(cnt2>n/3)
        res.push_back(m2);
        
        return res;
    }
};