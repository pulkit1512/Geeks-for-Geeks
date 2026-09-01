class Solution {
  public:
  
    void dfs1(int node,vector<vector<int>>&adj,vector<bool>&visited,stack<int>&s){
        visited[node]=1;
        
        for(int i=0;i<adj[node].size();i++){
            if(!visited[adj[node][i]]){
                dfs1(adj[node][i],adj,visited,s);
            }
        }
        s.push(node);
    }
    
    void dfs2(int node,vector<vector<int>>&adj,vector<bool>&visited){
        
        visited[node]=1;
        for(int i=0;i<adj[node].size();i++){
            if(!visited[adj[node][i]]){
                dfs2(adj[node][i],adj,visited);
            }
        }
    }
    int kosaraju(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj1(V);
        vector<vector<int>>adj2(V);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj1[u].push_back(v);
            adj2[v].push_back(u);
        }
        
        stack<int>s;
        vector<bool>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs1(i,adj1,visited,s);
            }
        }
        vector<bool>visited2(V,0);
        int count=0;
        while(!s.empty()){
            int node=s.top();
            s.pop();
            
            if(!visited2[node]){
                count++;
                dfs2(node,adj2,visited2);
            }
        }
        return count;
    }
};