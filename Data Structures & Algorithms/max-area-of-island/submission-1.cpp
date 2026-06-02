class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int maxi = 0;
        int cnt = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    dfs(i,j,vis,grid,cnt);
                    maxi = max(cnt,maxi);
                    cnt = 1;
                }
            }
        }
        return maxi;
    }
private:
    void dfs(int row, int col, vector<vector<int>>& vis,  vector<vector<int>>& grid,  int& cnt){
        vis[row][col]=1;
        int n = grid.size();
        int m = grid[0].size();

        int delR[] = {-1,1,0,0};
        int delC[] = {0,0,-1,1};

        for(int i=0; i<4; i++){
            int nrow = row + delR[i];
            int ncol = col + delC[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
               vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                cnt++;
                dfs(nrow,ncol,vis,grid,cnt);
            }
        }
    }
};
