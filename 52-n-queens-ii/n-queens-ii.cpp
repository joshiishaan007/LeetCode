class Solution {
public:
    int totalNQueens(int n) {
        vector<string> board;
        string s(n,'.');
        int count = 0, numberOfQueens = 0;

        for(int i=0; i<n; i++){
            board.push_back(s);
        }

        vector<int> rowHash(n,0);
        vector<int> upperDiagonal(2*n-1, 0);
        vector<int> lowerDiagonal(2*n-1, 0);

        solve(0, board, rowHash, upperDiagonal, lowerDiagonal, n, count, numberOfQueens);

        return count;
    }

    void solve(int col, vector<string>& board, vector<int>& rowHash,
    vector<int>& ud, vector<int>& ld, int n, int& count, int numberOfQueens){

        if(col == n && numberOfQueens == n){
            count++;
        }

        for(int row=0; row<n; row++){
            if(rowHash[row] == 0 && ud[n-1+col-row] == 0 && ld[row+col] == 0){
                board[row][col] = 'Q';
                numberOfQueens++;
                rowHash[row] = 1;
                ud[n-1+col-row] = 1;
                ld[row+col] = 1;
                solve(col+1, board, rowHash, ud, ld, n, count, numberOfQueens);
                board[row][col] = '.';
                numberOfQueens--;
                rowHash[row] = 0;
                ud[n-1+col-row] = 0;
                ld[row+col] = 0;
            }
        }
    }
};