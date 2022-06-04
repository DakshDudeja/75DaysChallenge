class Solution {
public:
        vector<vector<string>> ans;

     bool isValid(vector<string> &board, int row, int col){
        // check col
        for(int i=row;i>=0;--i)
            if(board[i][col] == 'Q') return false;
        // check left diagonal
        for(int i=row,j=col;i>=0&&j>=0;--i,--j)
            if(board[i][j] == 'Q') return false;
        //check right diagonal
        for(int i=row,j=col;i>=0&&j<board.size();--i,++j)
            if(board[i][j] == 'Q') return false;
        return true;
    }
    void solve(int n,int row,vector<string>&board){
        if(row==board.size()){
            ans.push_back(board);
            return;
        }
        if(row<0 ) return;
        for(int col =0;col<board.size();col++){
            if(isValid(board,row,col)){
                board[row][col] = 'Q';
                solve(n,row+1,board);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
         if(n <= 0) return {{}};
        vector<string> board(n,string(n,'.'));
        solve(n,0,board);
        return ans;
    }
};