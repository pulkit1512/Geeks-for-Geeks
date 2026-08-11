class Solution {
  public:
    bool isPossible(int n, vector<pair<int, int>>& pre) {
        // code here
        vector<vector<int>>adj(n);
        vector<int>indeg(n);
        for(int i=0;i<pre.size();i++){
            int u=pre[i].second;
            int v=pre[i].first;
            adj[u].push_back(v);
            indeg[v]++;
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
        int count=ans.size();
        return count==n;
        
        
    }
};