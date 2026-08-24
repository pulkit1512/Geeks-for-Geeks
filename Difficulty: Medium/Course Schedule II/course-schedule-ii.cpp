class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(n);
        vector<int>indeg(n,0);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[v].push_back(u);
            indeg[u]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(!indeg[i]){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int i=0;i<adj[node].size();i++){
                indeg[adj[node][i]]--;
                if(indeg[adj[node][i]]==0){
                    q.push(adj[node][i]);
                }
            }
        }
        if(ans.size()!=n) return {};
        return ans;
        
    }
};