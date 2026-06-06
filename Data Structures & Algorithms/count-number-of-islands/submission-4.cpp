class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;

        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    cnt++;
                    dfs(i,j,vis,grid,n,m);
                }
            }
        }
        return cnt;
    }
private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid, int n, int m){
        vis[row][col]=1;

        int delR[] = {-1,1,0,0};
        int delC[] = {0,0,-1,1};

        for(int i=0; i<4; i++){
            int nrow = row + delR[i];
            int ncol = col + delC[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]=='1'){
                dfs(nrow,ncol,vis,grid,n,m);
            }
        }
    }
};
