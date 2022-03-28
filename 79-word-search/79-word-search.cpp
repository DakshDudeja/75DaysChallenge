class Solution {
public:
    bool solve(vector<vector<char>>&board,int i,int j,int idx,string &word){
        if(idx==word.size()) return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[idx]) return false;
        
        board[i][j]='*'; // marking visited
       
        if(solve(board,i+1,j,idx+1,word)==true) return true;
        if(solve(board,i,j+1,idx+1,word)==true) return true;
        if(solve(board,i-1,j,idx+1,word)==true) return true;
        if(solve(board,i,j-1,idx+1,word)==true) return true;
        board[i][j]= word[idx];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                  if(board[i][j]==word[0])
                    if(solve(board,i,j,0,word)==true) return true;
          }
       }
        return false;
    }
        
};