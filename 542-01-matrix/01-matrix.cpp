class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m,-1));

        // {r,{c,level}}
        queue<pair<int,pair<int,int>>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    vis[i][j] = 1;
                    q.push({i,{j,0}});
                }
            }
        }

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second.first;
            int l = q.front().second.second;
            q.pop();

            dist[r][c] = l;

            for(int i=0; i<4; i++){
                int row = r + drow[i];
                int col = c + dcol[i];

                if(row>=0 && row<n && col>=0 && col<m && mat[row][col] == 1 && vis[row][col] == 0){
                    vis[row][col] = 1;
                    q.push({row,{col, l+1}});
                }
            }
        }

        return dist;
        
    }
};