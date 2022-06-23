class Solution {
public:
    vector<int>res;
    void solve(TreeNode* root){
        if(root==NULL)return;
        
        solve(root->left);
        res.push_back(root->val);
        solve(root->right);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        solve(root);
        return res;
    }
};