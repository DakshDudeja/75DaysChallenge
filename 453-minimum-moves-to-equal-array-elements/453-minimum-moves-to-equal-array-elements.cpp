class Solution {
public:
    int minMoves(vector<int>& nums) {
        //
        int mini=*min_element(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=abs(nums[i]-mini);
        }
        return ans;
    }
};


//1 2 3 4    
//2 3 4 4 
//3 4 5 4
//4 5 5 5

//5 5 6 6 

//6 6 6 7
//7 7 7 7



//1 2 3
//2 3 3
//3 4 3
//4 4 4
