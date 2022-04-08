class KthLargest {
private:
    TreeNode* _root;
    int _k;
    int _size;
public:
    // Obtain the minimum value of the tree
    int findMin() {
        TreeNode* node = _root;
        while (node->left != NULL)
            node = node->left;
        return node->val;
    }
    
    // Obtain the smallest value in the tree > than root->val
    int successor(TreeNode* root) {
        root = root->right;
        while (root->left != NULL) 
            root = root->left;
        return root->val;
    }
    
    // Obtain the largest value in the tree <= node->val
    int predecessor(TreeNode* root) {
      
        while (root->right != NULL) 
            root = root->right;
        return root->val;
    }

    // If the tree has an extra node, prune off the smallest one
    TreeNode* pruneToK(TreeNode* root) {
        if (_size <= _k)
            return root;
        if (root == NULL) {
            return NULL;
        } else if (root->left != NULL) {
            // delete from the left subtree
            root->left = pruneToK(root->left);
        } else {
            --_size;
            if (root->left == NULL && root->right == NULL) {
                // the node is a leaf
                root = NULL;
            } else if (root->right != NULL) {
                // the node is not a leaf and has a right child
                root->val = successor(root);
                root->right = deleteNode(root->right, root->val);
            } 
        }
        return root;
    }
    
    // Delete a node with val=key from the tree rooted at 'root'
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) 
            return NULL;
        if (key > root->val) {
            // delete from the right subtree
            root->right = deleteNode(root->right, key);
        } else if (key < root->val) {
            // delete from the left subtree
            root->left = deleteNode(root->left, key);
        } else {
            if (root->left == NULL && root->right == NULL) {
                // the node is a leaf
                root = NULL;
            } else if (root->right != NULL) {
                // the node is not a leaf and has a right child
                root->val = successor(root);
                root->right = deleteNode(root->right, root->val);
            } else {
                // the node is not a leaf, has no right child, and has a left child    
                root->val = predecessor(root);
                root->left = deleteNode(root->left, root->val);
            }
        }
        return root;
    }
    
    // insert a node into the tree at 'root' with a value 'val'
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            ++_size;
            return new TreeNode(val);
        } else if (val > root->val) {
            root->right = insertIntoBST(root->right, val);
        } else {
            root->left = insertIntoBST(root->left, val);
        }
        return root;
    }
    
    KthLargest(int k, vector<int>& nums) : _k(k), _root(NULL), _size(0) {
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            _root = insertIntoBST(_root, *it);
            _root = pruneToK(_root);
        }
    }
    
    int add(int val) {
        _root = insertIntoBST(_root, val);
        _root = pruneToK(_root);
        return findMin();
    }
};