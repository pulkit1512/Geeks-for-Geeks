class Solution {
  public:
    void dfs(vector<vector<pair<int,int>>>&adj,stack<int>&s,vector<bool>&visited,int node){
        visited[node]=1;
        for(int i=0;i<adj[node].size();i++){
            if(!visited[adj[node][i].first]){
                dfs(adj,s,visited,adj[node][i].first);
            }
        }
        s.push(node);
    }
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>>adj(V);
        vector<bool>visited(V,0);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int weight=edges[i][2];
            
            adj[u].push_back({v,weight});
        }
        
        stack<int>s;
        
        dfs(adj,s,visited,0);
        
        vector<int>dist(V,1e9);
        dist[0]=0;
        while(!s.empty()){
            auto node=s.top();
            s.pop();
            for(int i=0;i<adj[node].size();i++){
                auto [neighbour,weight]=adj[node][i];
                
                dist[neighbour]=min(dist[neighbour],dist[node]+weight);
            }
        }
        for(int i=0;i<V;i++){
            if(dist[i]==1e9) dist[i]=-1;
        }
        return dist;
    }
};
