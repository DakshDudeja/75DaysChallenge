
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        while(root){
            if(root->left){
                TreeNode* left =root->left;
                TreeNode* curr=left;
                while(curr->right) curr=curr->right;
                curr->right =root->right;
                root->left = NULL;
                root->right=left;
            }
            root=root->right;
        }
    }
};