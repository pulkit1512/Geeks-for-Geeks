class Solution {
	public:
	
	bool dfs(vector<vector<int>> &adj, vector<bool>&visited, int parent, int node) {
		visited[node] = 1;
		for (int i = 0; i<adj[node].size(); i++) {
			if (parent == adj[node][i])
				continue;
			if (visited[adj[node][i]])
				return 1;
			if (dfs(adj, visited, node, adj[node][i])) {
				return 1;
			}
		}
		return 0;
	}
	bool isCycle(int V, vector<vector<int>> & edges) {
		// Code here
		vector<vector<int>> adj(V);
		for (int i = 0; i<edges.size(); i++) {
			int u = edges[i][0];
			int v = edges[i][1];
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		// handle case for the broken graph
		vector<bool>visited(V, 0);
		for (int i = 0; i<V; i++) {
			if (!visited[i]) {
				if (dfs(adj, visited, -1, i)) {
					return 1;
				}
			}
		}
		return 0;
		
	}
};
