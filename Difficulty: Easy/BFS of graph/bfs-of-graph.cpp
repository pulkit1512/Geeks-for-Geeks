class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int V = adj.size();
        vector<bool> visited(V, false);
        queue<int> q;
        vector<int> ans;

        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (int i = 0; i < adj[node].size(); i++) {
                int neighbor = adj[node][i];
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return ans;
    }
};
