class Solution {
  public:
    bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& path) {
        visited[node] = true;
        path[node] = true;
        
        for (int i = 0; i < adj[node].size(); i++) {
            int neighbor = adj[node][i];
            
            // If the neighbor is already in the current recursion stack, a cycle exists
            if (path[neighbor]) return true;
            
            // If the neighbor is not visited, explore it recursively
            if (!visited[neighbor]) {
                if (dfs(neighbor, adj, visited, path)) return true;
            }
        }
        
        // Backtrack: remove from current recursion path
        path[node] = false;
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        
        vector<bool> visited(V, false);
        vector<bool> path(V, false);
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, path)) return true;
            }
        }
        
        return false;
    }
};