class Solution {
public:
bool isSafe(vector<string>&board,int row,int col,int n){
    //upward
for(int i=0;i<row;i++){
    if(board[i][col]=='Q') return false;
}
for(int i=row-1,j=col-1;i>=0 &&j>=0;i--,j--){
    if(board[i][j]=='Q') return false;
}

for(int i=row-1,j=col+1;i>=0 && j<n ;i--,j++){
    if(board[i][j]=='Q') return false;
}
   return true; 
}
    void solve(vector<vector<string>>&ans,vector<string>&board,int row,int n){
        // row=0;
        if(row>=n){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(isSafe(board,row,col,n)){
                board[row][col]='Q';
                solve(ans,board,row+1,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        int row=0;
        vector<vector<string>>ans;
        vector<string> board(n, string(n, '.'));
        solve(ans,board,0,n);
        return ans;
    }
};