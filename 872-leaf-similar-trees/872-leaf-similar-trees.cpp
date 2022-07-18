
class Solution {
public:
    vector<int>a;
    void solve(TreeNode* root){
        if(root==NULL) return;
        if(root->left==NULL and root->right==NULL)a.push_back(root->val);
        solve(root->left);
        solve(root->right);
        return;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        solve(root1);
        solve(root2);
        int i=0,j=(a.size()/2);
        if(a.size()%2!=0) return false;
        for(int i=0,j=(a.size()/2);i<(a.size()/2) and j<a.size();i++,j++){
            if(a[i]==a[j])continue;
            else
                return false;
        }
        return true;
    }
};