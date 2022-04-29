
class Solution {
public:
    TreeNode* creatree(vector<int>& pre,int pre_start,int pre_end, vector<int>& post,int post_start, int post_end){
         if(pre_start>pre_end)
    {
        return NULL;
    }
        TreeNode *root=new TreeNode(pre[pre_start]);
        if(pre_start==pre_end) return root;
        
        int index= post_start;
        while(post[index]!=pre[pre_start+1]){
            index++;
        }
        int len = index-post_start+1;
        root->left=creatree(pre,pre_start+1,pre_start+len,post,post_start,index);
        root->right=creatree(pre,pre_start+len+1,pre_end,post,index+1,post_end-1);
        return root;  
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return creatree(pre,0,pre.size()-1,post,0,post.size()-1);
            
    }
};