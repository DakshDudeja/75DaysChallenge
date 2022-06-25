
class Solution {
public:
     TreeNode* solve(vector<int> &postorder,int postStart,int postEnd ,vector<int>& inorder,int inStart,int inEnd,map<int,int>&mp){
        
        if(postStart > postEnd || inStart > inEnd)
            return NULL;
        
        TreeNode* root = new TreeNode(postorder[postEnd]);
         int inRoot = mp[root->val];
        int numsLeft = inRoot - inStart;
        
        TreeNode* leftchild =  solve(postorder,postStart,postStart+numsLeft-1,inorder,inStart,inRoot-1,mp);
        TreeNode* rightchild =  solve(postorder,postStart+numsLeft,postEnd-1,inorder,inRoot+1,inEnd,mp);
        
        root->left = leftchild;
        root->right = rightchild;
         
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()) return NULL;
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
     return solve(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mp);
        
    }
};