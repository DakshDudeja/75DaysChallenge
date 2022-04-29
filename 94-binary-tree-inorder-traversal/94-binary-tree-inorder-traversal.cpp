/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void addLeftSubTree(TreeNode *temp,stack<TreeNode*>&st){
        st.push(temp);
        while(temp->left!=NULL){
            st.push(temp->left);
            temp=temp->left;
        }
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
         vector<int>res;
        stack<TreeNode*>st;
        if(root==NULL) return res;
        addLeftSubTree(root,st);

        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();
            res.push_back(temp->val);
            
            if(temp->right)
                addLeftSubTree(temp->right,st);            
        }
        return res;
    }
};