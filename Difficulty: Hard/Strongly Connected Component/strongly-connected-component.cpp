class Solution {
	public:
	void dfs(int node, vector<vector<int>> &adj,  vector<int>&disc, vector<int>&low, vector<vector<int>> &ans, vector<bool>&visited, int &count, stack<int>&s, vector<bool>&instack) {
		visited[node] = 1;
		instack[node] = 1;
		s.push(node);
		disc[node] = low[node] = count;
		
		for (int i = 0; i<adj[node].size(); i++) {
			
			if (visited[adj[node][i]]) {
				if (instack[adj[node][i]]) {
					low[node] = min(low[node], low[adj[node][i]]);
				}
			}
			else {
				count++;
				dfs(adj[node][i], adj, disc, low, ans, visited, count, s, instack);
				low[node] = min(low[adj[node][i]], low[node]);
			}
		}
		
		if (low[node] == disc[node]) {
			vector<int>temp;
			
			while (!s.empty() && s.top() != node) {
				temp.push_back(s.top());
				instack[s.top()] = 0;
				s.pop();
			}
			
			temp.push_back(s.top());
			instack[s.top()] = 0;
			s.pop();
			sort(temp.begin(), temp.end());
			ans.push_back(temp);
			
		}
		
	}
	vector<vector<int>> tarjans(int V, vector<vector<int>> & adj) {
		// code here
		vector<vector<int>> ans;
		vector<int>low(V);
		vector<int>disc(V);
		vector<bool>visited(V, 0);
		vector<bool>instack(V, 0);
		int count = 0;
		stack<int>s;
		for (int i = 0; i<V; i++) {
		    if(!visited[i])
			dfs(i, adj, disc, low, ans, visited, count, s, instack);
			
		} sort(ans.begin(), ans.end());
		return ans;
	}
};
