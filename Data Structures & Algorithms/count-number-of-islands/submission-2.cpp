class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }

    void bfs(int r, int c, vector<vector<int>>& vis, vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        vis[r][c]=1;
        queue<pair<int,int>> q;
        q.push({r,c});

        int delR[] = {0,0,1,-1};
        int delC[] = {1,-1,0,0};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = r + delR[i];
                int ncol = c + delC[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
                    && vis[nrow][ncol]==0 && grid[nrow][ncol]=='1')
                    {
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
            }
        }
    }
};
