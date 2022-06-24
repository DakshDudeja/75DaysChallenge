
class Solution {
public:
    int ans=0;
    int solve(TreeNode* root){
        if(root==NULL) return 0;
        
        int l=solve(root->left);
        int r=solve(root->right);
        ans=max(ans,abs(l-r));
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        solve(root);
        if(ans<=1) return true;
        else return false;
    }
};