class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<int>traversal;
        InorderTraversal(root,traversal);
        
        TreeNode* dummy =  new TreeNode(-1);
        TreeNode* newroot = dummy;
        for(auto i : traversal)
        {
            dummy->right = new TreeNode(i);  // create a new node
            dummy = dummy->right;   // setting the new node to the right
        }
        return newroot->right;
    }
    void InorderTraversal(TreeNode*root, vector<int>&ans)
    {
        if(root==NULL) return;
        InorderTraversal(root->left,ans);
        ans.push_back(root->val);
        InorderTraversal(root->right,ans);
    }
};