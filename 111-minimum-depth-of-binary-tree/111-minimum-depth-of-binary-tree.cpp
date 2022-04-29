
class Solution {
public:
    int solve(TreeNode* root){
        if(root==nullptr) return INT_MAX;
        if(root->left == nullptr and root->right==nullptr) return 1;
        int l = solve(root->left);
        int r = solve(root->right);
        return min(l,r)+1;
    }
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        return solve(root);
    }
};