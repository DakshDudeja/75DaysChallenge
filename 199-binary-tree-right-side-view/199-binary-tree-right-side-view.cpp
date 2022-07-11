class Solution {
public:
    vector<int>res;
    set<int>st;
    void solve(TreeNode* root,int level){
        if(root==NULL) return;
        if(!st.count(level)){
            res.push_back(root->val);
            st.insert(level);
        }
        solve(root->right,level+1);
        solve(root->left,level+1);
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        solve(root,0);
        return res;
    }
};