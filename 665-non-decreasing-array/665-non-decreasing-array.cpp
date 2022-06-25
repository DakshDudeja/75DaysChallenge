class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool is_modified = false;
        for (int i = 1, prev = nums[0]; i < nums.size(); i++) {
            if (nums[i] < prev) {
                if (is_modified) return false;
                is_modified = true;
                if (i - 2 >= 0 && nums[i-2] > nums[i]) continue;
                
            }
            prev = nums[i];
        }
        return true;
    }
};