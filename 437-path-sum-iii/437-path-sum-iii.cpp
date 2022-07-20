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
	long long cnt=0;
	void solve(TreeNode* root,int targetSum,long long pre,unordered_map<long long,int>mp){
		if(root==NULL)return;
        pre+=root->val;
		if(mp.find(pre-targetSum)!=mp.end())cnt+=mp[pre-targetSum];
		
		mp[pre]++;
		solve(root->left,targetSum,pre,mp);
		solve(root->right,targetSum,pre,mp);
        mp[pre]--;
	}

    int pathSum(TreeNode* root, int targetSum) {
          unordered_map<long long,int>mp;
          mp[0]=1;
         solve(root,targetSum,0,mp);
	   return cnt;
    }
};