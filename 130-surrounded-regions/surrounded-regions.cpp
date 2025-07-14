class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,1,0,-1};

        // for first row
        for(int i=0; i<m; i++){
            if(!vis[0][i] && board[0][i] == 'O'){
                dfs(board, vis, 0, i, drow, dcol);
            }
        }

        // for last row
        for(int i=0; i<m; i++){
            if(!vis[n-1][i] && board[n-1][i] == 'O'){
                dfs(board, vis, n-1, i, drow, dcol);
            }
        }

        // for first col
        for(int i=0; i<n; i++){
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(board, vis, i, 0, drow, dcol);
            }
        }

        // for lats col
        for(int i=0; i<n; i++){
            if(!vis[i][m-1] && board[i][m-1] == 'O'){
                dfs(board, vis, i, m-1, drow, dcol);
            }
        }

        //usign vis matrix convert "O" to "X"
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board,vector<vector<bool>>& vis, int r, int c, vector<int> drow, vector<int> dcol){
        
        vis[r][c] = true;

        for(int i=0; i<4; i++){
            int row = r + drow[i];
            int col = c + dcol[i];

            if(row>=0 && row<board.size() && col>=0 && col<board[0].size() && !vis[row][col] && board[row][col] == 'O'){
                dfs(board, vis, row,col, drow, dcol);
            }
        }
    }

    
};