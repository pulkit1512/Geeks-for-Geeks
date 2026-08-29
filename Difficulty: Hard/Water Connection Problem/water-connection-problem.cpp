class Solution {
  public:
  
    void dfs(int node,vector<vector<pair<int,int>>>&adj,vector<int>&indeg,vector<int>&outdeg,vector<int>&temp,vector<vector<int>>&ans,int weight,vector<bool>&visited){
        visited[node]=1;
        if(outdeg[node]==0){
            temp.push_back(node);
            temp.push_back(weight);
            ans.push_back(temp);
            return ;
        }
        
        for(int i=0;i<adj[node].size();i++){
            auto [neigh,dia]=adj[node][i];
            
            
            dfs(neigh,adj,indeg,outdeg,temp,ans,min(weight,dia),visited);
        }
    }
    vector<vector<int>> solve(int n, int p, vector<int> &a, vector<int> &b,
                              vector<int> &d) {
        // code here
        vector<vector<pair<int,int>>>adj(n+1);
        vector<int>indeg(n+1,0);
        vector<int>outdeg(n+1,0);
        for(int i=0;i<p;i++){
            int u=a[i];
            int v=b[i];
            int w=d[i];
            
            adj[u].push_back({v,w});
            indeg[v]++;
            outdeg[u]++;
        }
        vector<vector<int>>ans;
        
        vector<bool>visited(n+1,0);
        for(int i=1;i<=n;i++){
            if(!visited[i]&&outdeg[i] == 1 && indeg[i] == 0){
                vector<int>temp;
                int weight=INT_MAX;
                temp.push_back(i);
                dfs(i,adj,indeg,outdeg,temp,ans,weight,visited);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};