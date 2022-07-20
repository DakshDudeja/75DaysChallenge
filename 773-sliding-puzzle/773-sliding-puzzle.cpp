class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int n=board.size(),m=board[0].size();
        string s;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                s+=to_string(board[i][j]);
            }
        }
        vector<vector<int>>dir={{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{4,2}};
        queue<string>q;
        q.push(s);
        int level=0;
        string ans="123450";
        set<string>vis;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                string curr=q.front();
                q.pop();
                if(curr==ans)return level;
                
                int idx=-1;
                for(int i=0;i<curr.size();i++){
                    if(curr[i]=='0'){
                        idx=i;
                        break;
                    }
                }
                vector<int> direction=dir[idx];
                for(auto it:direction){
                    string temp=curr;
                    swap(temp[it],temp[idx]);
                    
                    if(vis.count(temp))continue;
                        
                    q.push(temp);
                    vis.insert(temp);
                }
            }
            level++;
        }
        return -1;
    }
};