class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 && j==0){
                    dp[i][j] = grid[i][j];
                }else{
                    int upVal = INT_MAX, leftVal = INT_MAX;
                    if(i>0) upVal = dp[i-1][j];
                    if(j>0) leftVal = dp[i][j-1];
                    dp[i][j] = grid[i][j] + min(upVal,leftVal);
                }
            }
        }

        return dp[n-1][m-1];
    }
};