class BSTIterator {
public:
    stack<TreeNode*>st;
    
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
      
    void pushAll(TreeNode* root){
        while(root != NULL){
            st.push(root);
            root = root->left;
        }
    }

    int next() {
        TreeNode* top = st.top();
        st.pop();
        pushAll(top->right);
        return top->val;
    }
    
    bool hasNext() {
        if(!st.empty()) return true;
        else
            return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */