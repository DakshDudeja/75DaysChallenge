class Solution {
    struct S {
        bool isBST;
        int minVal; 
        int maxVal; 
        int sum;
    };
    
    S helper(TreeNode *node, int &res) {
        if (!node) {
            return { true, INT_MAX, INT_MIN, 0 };
        }
        S l = helper(node->left, res);
        S r = helper(node->right, res);
        if (l.isBST && r.isBST && l.maxVal < node->val && r.minVal > node->val) {
            int sum = l.sum + r.sum + node->val;
            res = max(res, sum);
            return { true, min(l.minVal, node->val), max(r.maxVal, node->val), sum };
        } else {
            return { false, INT_MIN, INT_MAX, 0 };
        }
    }
public:
    int maxSumBST(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
};
