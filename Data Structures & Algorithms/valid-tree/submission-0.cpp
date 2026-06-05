class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // Condition 1: tree with n nodes must have exactly n-1 edges
        if (edges.size() != n - 1) return false;

        vector<vector<int>> adj(n);
        for(auto& it:edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n,0);
        dfs(0,vis,adj);

        for(int i=0; i<n; i++){
            if(vis[i]==0) return false;
        }
        return true;
    }
private:
    void dfs(int node, vector<int>& vis, vector<vector<int>> adj){
        vis[node]=1;

        for(auto it:adj[node]){
            if(vis[it]==0){
                dfs(it,vis,adj);
            }
        }
    }
};
