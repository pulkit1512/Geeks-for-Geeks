class Solution {
	public:
	vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
		// Code here
		
		vector<vector<pair<int, int>> >adj(V);
		for (int i = 0; i<edges.size(); i++) {
			int u = edges[i][0];
			int v = edges[i][1];
			int weight = edges[i][2];
			adj[u].push_back({v, weight});
			adj[v].push_back({u, weight});
			
		}
		vector<bool>explore(V, 0);
		vector<int>dist(V, INT_MAX);
		dist[src]=0;
	    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	    
	    pq.push({0,src});
	    while(!pq.empty()){
	        int node=pq.top().second;
	        pq.pop();
	        if(explore[node]) continue;
	        explore[node]=1;
	        for(int i=0;i<adj[node].size();i++){
	            auto [neighbour,weight]=adj[node][i];
	            if(!explore[neighbour]&&dist[node]+weight<dist[neighbour]){
	                dist[neighbour]=dist[node]+weight;
	                pq.push({dist[neighbour],neighbour});
	            }
	        }
	    }
	    return dist;
	}
};
