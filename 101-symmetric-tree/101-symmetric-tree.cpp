
class Solution {
public:
    bool solve(TreeNode* root1,TreeNode* root2){
        if(root1==NULL and root2==NULL) return true;

        if( (root1->left==NULL and root2->right!=NULL) ||(root2->left==NULL and root1->right!=NULL ))return false;
    if((root1->right==NULL and root2->left!=NULL) || (root2->right==NULL and root1->left!=NULL)) return false;
        
        if(root1->val!=root2->val) return false;
        return solve(root1->right,root2->left) and solve(root1->left,root2->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return false;
        return solve(root,root);
    }
};