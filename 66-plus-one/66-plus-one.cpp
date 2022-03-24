class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        
        int carry=0;
        
        int i=digits.size()-1;
   
        vector<int> ans;
        int sum=1;
        
        while(i>=0 || carry)
        {
            if(i>=0)
            {
                sum+=digits[i];
                i-=1;
            }
            sum+=carry;
            carry=sum/10;
            ans.push_back(sum%10);
            sum=0;
        }
        
        reverse(ans.begin(),ans.end());
         return ans;
        
        
        
    }
};