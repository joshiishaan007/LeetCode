class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        vector<vector<bool>> vis(n,vector<bool>(m,false));

        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,1,0,-1};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(!vis[i][j] && grid[i][j] == 1){
                        dfs(grid, vis, i, j, drow, dcol);
                    }
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    count++;
                }
            }
        }

        return count;
    }

    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int r, int c, vector<int>& drow, vector<int>& dcol){

        vis[r][c] = true;

        for(int i=0; i<4; i++){
            int row = r + drow[i];
            int col = c + dcol[i];

            if(row>=0 && row<grid.size() && col>=0 && col<grid[0].size() && !vis[row][col] && grid[row][col] == 1){
                dfs(grid, vis, row, col, drow, dcol);
            }
        }
    }
};