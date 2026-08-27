class Solution {
  public:
  void dfs(int node,vector<int>adj[],vector<bool>&visited){
      visited[node]=1;
      for(int i=0;i<adj[node].size();i++){
          if(!visited[adj[node][i]]){
              dfs(adj[node][i],adj,visited);
          }
      }
  }
    bool isCircle(vector<string> &arr) {
        // code here
        int n=arr.size();
        vector<int>adj[26];
        vector<int>indeg(26,0);
        vector<int>outdeg(26,0);
        
        for(int i=0;i<n;i++){
            int u=arr[i][0]-'a';
            int v=arr[i][arr[i].size()-1]-'a';
            adj[u].push_back(v);
            indeg[v]++;
            outdeg[u]++;
        }
        
        for(int i=0;i<26;i++){
            if(indeg[i]!=outdeg[i]) return 0;
        }
        
        vector<bool>visited(26,0);
        
        int node=arr[0][0]-'a';
        
        dfs(node,adj,visited);
        
        for(int i=0;i<26;i++){
            if(indeg[i]&&!visited[i]) return 0;
        }
        return 1;
    }
};