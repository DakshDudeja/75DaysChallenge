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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push(make_pair(root,0));
         int ans=0;
        while(!q.empty()){
            int size=q.size();
            int start = q.front().second;
            int end = q.back().second;
            ans=max(ans,end-start+1);
            for(int i=0;i<size;i++){
                auto temp = q.front();
                q.pop();
                long long  n=temp.second-start;
                if(temp.first->left)q.push({temp.first->left,2*n});
                if(temp.first->right)q.push({temp.first->right,2*n+1});
            }
        }
        return ans;
    }
};