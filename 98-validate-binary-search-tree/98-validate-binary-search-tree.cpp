class Solution {
public:
    bool solve(TreeNode* root,long long mini,long long maxi){
        if(!root) return true;
        else if(root->val <= mini or root->val >= maxi) return false;
        
        bool ls = solve(root->left,mini,root->val);
        bool rs = solve(root->right,root->val,maxi);
        bool res = ls and rs;
        return res;
    }
    bool isValidBST(TreeNode* root){
        long long lowRange = pow(-2,31)-1;
        long long highRange = pow(2,31);        
        return solve(root,lowRange,highRange);
    }
};