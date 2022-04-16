
class Solution {
public:
    int sum=0;
    TreeNode* dfs(TreeNode* root){
        if(!root) return nullptr;
        dfs(root->right);
        root->val = root->val+sum;
        sum=root->val;
        dfs(root->left);
        return root;}
    
    TreeNode* convertBST(TreeNode* root) {
       dfs(root);
        return root; 
    }
};