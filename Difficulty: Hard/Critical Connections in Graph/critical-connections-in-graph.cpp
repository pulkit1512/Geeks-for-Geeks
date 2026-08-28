class Solution {
  public:
    void dfs(vector<vector<int>>&adj,int node,int parent,vector<int>&disc,vector<int>&low,int count,vector<vector<int>>&ans,vector<bool>&visited){
        disc[node]=low[node]=count;
        
        visited[node]=1;
        
        for(int i=0;i<adj[node].size();i++){
            int neigh=adj[node][i];
            
            if(neigh==parent) continue;
            else if(visited[neigh]){
                low[node]=min(low[neigh],low[node]);
            }
            else{
                count++;
                dfs(adj,neigh,node,disc,low,count,ans,visited);
                if(low[neigh]>disc[node]){
                    ans.push_back({node,neigh});
                }
                low[node]=min(low[neigh],low[node]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>disc(V);
        vector<int>low(V);
        vector<bool>visited(V,0);
        int count=0;
        
        vector<vector<int>>ans;
        
        dfs(adj,0,-1,disc,low,count,ans,visited);
        
        return ans;
    }
};