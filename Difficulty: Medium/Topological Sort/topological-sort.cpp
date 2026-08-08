class Solution {
  public:
  
    void dfs(int node,vector<vector<int>>&adj,vector<bool>&visited,stack<int>&s){
        visited[node]=1;
        for(int i=0;i<adj[node].size();i++){
            if(!visited[adj[node][i]]){
                dfs(adj[node][i],adj,visited,s);
            }
        }
        s.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<bool>visited(V,0);
        stack<int>s;
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
        }
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,visited,s);
            }
        }
        
        vector<int>ans;
        while(!s.empty()){
            int node=s.top();
            s.pop();
            ans.push_back(node);
        }
        return ans;
    }
};