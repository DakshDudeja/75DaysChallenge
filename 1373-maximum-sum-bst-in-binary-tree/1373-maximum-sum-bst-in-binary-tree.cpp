
class Solution {
public:
    struct Node{
        bool isBst;
        int minVal;
        int maxVal;
        int sum;
    };
    
    Node solve(TreeNode* root,int &res){
        if(!root) return{true,INT_MAX,INT_MIN,0} ;
            
        Node left = solve(root->left,res);
        Node right = solve(root->right,res);
        
        if(left.isBst==true && right.isBst==true and left.maxVal <root->val and right.minVal > root->val){
            int sum=left.sum+right.sum+root->val;
            res=max(res,sum);
            return {true,min(left.minVal,root->val) ,max(right.maxVal,root->val),sum};
        }
        else{
            return {false,INT_MIN,INT_MAX,0};
        }
    }
    
    int maxSumBST(TreeNode* root) {
        int res=0;
        solve(root,res);
        return res;
    }
};