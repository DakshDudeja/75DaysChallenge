
class Codec {
public:
    string serialize(TreeNode* root) {
     if(!root) return " ";
      string s;
      queue<TreeNode*>q;
      q.push(root);
        while(!q.empty()){
            auto curr =q.front();
            q.pop();
            if(curr==NULL){
                s+="#,";
            }
            else{
                s+=to_string(curr->val)+',';
            }
            if(curr!=NULL){
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        cout<<s;   //1,2,3,#,#,4,5,#,#,#,#,
        return s;
    }
    
    int getNum(string &s,int& i,int& n){
        string res="";
        while(i<n and s[i]!=',') res+=s[i++];
        i++;
        return stoi(res);
    }
    
    
    TreeNode* deserialize(string data) {
        if(data==" ") return NULL;
        queue<TreeNode*>q;
        int i=0,n=data.size();
        TreeNode* root = new TreeNode(getNum(data,i,n));
        q.push(root);
        while(!q.empty()){
                TreeNode* curr=q.front();
                q.pop();
                if(data[i]=='#')i+=2;
                else{
                    curr->left = new TreeNode(getNum(data,i,n));
                    q.push(curr->left);
                }
                if(data[i]=='#')i+=2;
                else{
                    curr->right = new TreeNode(getNum(data,i,n));
                    q.push(curr->right);
                }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));