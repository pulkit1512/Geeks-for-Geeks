class Solution {
  public:
  
    void dfs(vector<vector<int>>&adj,vector<bool>&visited,vector<int>&ans,int node){
        visited[node]=1;
        ans.push_back(node);
        for(int i=0;i<adj[node].size();i++){
            if(!visited[adj[node][i]]){
                dfs(adj,visited,ans,adj[node][i]);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int v=adj.size();
        vector<bool>visited(v,0);
        vector<int>ans;
        dfs(adj,visited,ans,0);
        return ans;
    }
};