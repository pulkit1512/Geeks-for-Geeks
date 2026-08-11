class Solution {
private:
    int dfs(int node, int dest, vector<vector<int>>& adj, vector<int>& dp) {
        if (node == dest) {
            return 1;
        }
        if (dp[node] != -1) {
            return dp[node];
        }
        
        int paths = 0;
        for (int neighbor : adj[node]) {
            paths += dfs(neighbor, dest, adj, dp);
        }
        
        return dp[node] = paths;
    }

public:
    int countPaths(int V, vector<vector<int>>& edges, int src, int dest) {
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        
        vector<int> dp(V, -1);
        return dfs(src, dest, adj, dp);
    }
};