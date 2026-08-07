class Solution {
  public:
     void dfs(vector<vector<int>>&adj,vector<bool>&visited,int node){
        visited[node]=1;
        for(int i=0;i<adj[node].size();i++){
            if(!visited[adj[node][i]]){
                dfs(adj,visited,adj[node][i]);
            }
        }
    }
    int countConnected(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count=0;
        vector<bool>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(adj,visited,i);
                count++;
            }
        }
        return count;
    }
};