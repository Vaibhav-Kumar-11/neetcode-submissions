class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int maxi = INT_MAX;
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        // Again ye multiple source bfs ki feel derha hai
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int distance = q.front().second;
            q.pop();

            int delR[] = {-1,1,0,0};
            int delC[] = {0,0,-1,1};

            for(int i=0; i<4; i++){
                int nrow = row + delR[i];
                int ncol = col + delC[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m 
                && grid[nrow][ncol]==maxi && vis[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    grid[nrow][ncol]=distance+1;
                    q.push({{nrow,ncol},distance+1});
                }
            }
        }
    }
};
