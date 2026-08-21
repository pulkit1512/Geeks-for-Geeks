class Solution {
	public:
	bool isNegativeWeightCycle(int V, vector<vector<int>> & edges) {
		// code here
		vector<int>dist(V, INT_MAX);
		dist[0] = 0;
		
		for (int i = 0; i<V - 1; i++) {
		    bool flag=0;
			for (int j = 0; j<edges.size(); j++) {
			    
				int u = edges[j][0];
				int v = edges[j][1];
				int weight = edges[j][2];
				if(dist[u]==INT_MAX) continue;
				if (dist[u]+weight<dist[v]) {
				    flag=1;
					dist[v] = dist[u]+weight;
				}
			}
			if(!flag) return 0;
		}
		for (int i = 0; i<edges.size(); i++) {
			int u = edges[i][0];
			int v = edges[i][1];
			int weight = edges[i][2];
			if (dist[u]+weight<dist[v]) {
				return true;
			}
		}
		return false;
	}
};
