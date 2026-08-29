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
    bool isCircle(vector<string> &arr) {
        // code here
        int n=arr.size();
        vector<int>indeg(26,0);
        vector<int>outdeg(26,0);
        vector<vector<int>>adj(26);
        for(int i=0;i<arr.size();i++){
            int u=arr[i][0]-'a';
            int v=arr[i][arr[i].size()-1]-'a';
            adj[u].push_back(v);
            indeg[v]++;
            outdeg[u]++;
        }
        
        for(int i=0;i<26;i++){
            if(indeg[i]!=outdeg[i]){
                return false;
            }
        }
        
        vector<bool>visited(26,0);
        
        for(int  i=0;i<26;i++){
            if(indeg[i]){
                dfs(adj,visited,i);
                break;
            }
        }
        for(int i=0;i<26;i++){
            if(indeg[i]&&!visited[i]) return false;
        }
        
        return true;
    }
};