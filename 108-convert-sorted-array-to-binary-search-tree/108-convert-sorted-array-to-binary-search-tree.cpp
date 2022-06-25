/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(int s,int e,vector<int>& nums){
        while(s<=e){
            int mid=s+(e-s)/2;
            
            TreeNode* root=new TreeNode(nums[mid]);
            root->left = solve(s,mid-1,nums);
            root->right = solve(mid+1,e,nums);
            return root;
        }
        return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return solve(0,n-1,nums);

    }
};