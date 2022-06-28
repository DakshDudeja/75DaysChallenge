class Solution {
public:
    
    TreeNode* solve(vector<int> &preorder,int &idx,int ub){
        if(idx == preorder.size() or preorder[idx] > ub) return NULL;
        
        TreeNode* root = new TreeNode(preorder[idx++]);
        
        root->left = solve(preorder,idx,root->val);
        root->right = solve(preorder,idx,ub);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder){
        int i=0;
        return solve(preorder,i,INT_MAX);
    }
};