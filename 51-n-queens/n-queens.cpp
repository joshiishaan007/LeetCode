class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        string s(n,'.');

        for(int i=0; i<n; i++){
            board.push_back(s);
        }

        vector<int> rowHash(n,0);
        vector<int> upperDiagonal(2*n-1, 0);
        vector<int> lowerDiagonal(2*n-1, 0);

        solve(0, board, ans, rowHash, upperDiagonal, lowerDiagonal, n);

        return ans;
    }

    void solve(int col, vector<string>& board, vector<vector<string>>& ans, vector<int>& rowHash,
    vector<int>& ud, vector<int>& ld, int n){

        if(col == n){
            ans.push_back(board);
        }

        for(int row=0; row<n; row++){
            if(rowHash[row] == 0 && ud[n-1+col-row] == 0 && ld[row+col] == 0){
                board[row][col] = 'Q';
                rowHash[row] = 1;
                ud[n-1+col-row] = 1;
                ld[row+col] = 1;
                solve(col+1, board, ans, rowHash, ud, ld, n);
                board[row][col] = '.';
                rowHash[row] = 0;
                ud[n-1+col-row] = 0;
                ld[row+col] = 0;
            }
        }
    }
};