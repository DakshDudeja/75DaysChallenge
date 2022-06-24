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
    int solve(TreeNode* root,int &sum){
        if(root==NULL) return 0;
        
         // sum=max(root->val,sum);
        int left =max(0,solve(root->left,sum));
        int right =max(0,solve(root->right,sum));

        // sum=max(sum,right+root->val);
        // sum=max(sum,left+root->val);
        // sum=max(sum,root->val);
        sum=max(sum,left+right+root->val);
        
        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        int sum=INT_MIN;
         solve(root,sum);
        return sum;
    }
};