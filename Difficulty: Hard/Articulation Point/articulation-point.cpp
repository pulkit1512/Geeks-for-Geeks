class Solution {
  public:
  
    void dfs(int node,int parent,vector<vector<int>>&adj,vector<int>&disc,vector<int>&low,int count,vector<bool>&arti,vector<bool>&visited){
        disc[node]=low[node]=count;
        
        visited[node]=1;
        
        int timer=0;
        for(int i=0;i<adj[node].size();i++){
            // if(adj[node].size()==1) break;
            int neigh=adj[node][i];
            
            if(neigh==parent) continue;
            
            else if(visited[neigh]) low[node]=min(low[node],disc[neigh]);
            
            else{
                count++;
                timer++;
                dfs(neigh,node,adj,disc,low,count,arti,visited);
               
                if(disc[node]<=low[neigh]&&parent!=-1){
                    arti[node]=1;
                }
                low[node]=min(low[node],low[neigh]);
            }
            
        }
        
        if(timer>1&&parent==-1){
            arti[node]=1;
        }
    }
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool>arti(V,0);
        
        vector<int>disc(V);
        vector<int>low(V);
        
        vector<bool>visited(V,0);
        
        for(int i=0;i<V;i++){
            int count=0;
            if(!visited[i]){
                dfs(i,-1,adj,disc,low,count,arti,visited);
            }
        }
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(arti[i]){
                ans.push_back(i);
            }
        }
        if(ans.size()==0) return {-1};
        return ans;
        
    }
};