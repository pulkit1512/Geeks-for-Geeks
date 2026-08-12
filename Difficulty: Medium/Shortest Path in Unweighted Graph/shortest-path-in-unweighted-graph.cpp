class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // code here
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u); 
        }
        vector<bool>visited(V,0);
        queue<tuple<int,int>>q;
        q.push({src,0});
        visited[src]=1;
        while(!q.empty()){
            auto  [node,c]=q.front();
            q.pop();
            if(node==dest) return c;
            
            for(int i=0;i<adj[node].size();i++){
                if(!visited[adj[node][i]]){
                    q.push({adj[node][i],c+1});
                    visited[adj[node][i]]=1;
                }
            }
            
    
        }
        return -1;
    }
};
