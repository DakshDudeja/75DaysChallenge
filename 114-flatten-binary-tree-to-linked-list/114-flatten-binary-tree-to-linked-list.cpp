class Solution {
public:
    // morrisTraversal
    void flatten(TreeNode* root) {
         TreeNode* cur = root;
		while (cur!=NULL)
		{
			if(cur->left!=NULL)
			{
				TreeNode* pre = cur->left;
				while(pre->right!=NULL)
				{
					pre = pre->right;
				}
				pre->right = cur->right;
				cur->right = cur->left;
				cur->left = NULL;
			}
			cur = cur->right;
		}
    }
};