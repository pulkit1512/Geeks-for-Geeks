class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>>adj(V);
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        vector<bool>visited(V,0);
        int sum=0;
        
        while(!pq.empty()){
            auto [w,node]=pq.top();
            pq.pop();
            if(visited[node]) continue;
            visited[node]=1;
            sum+=w;
            for(int i=0;i<adj[node].size();i++){
                auto [v,weight]=adj[node][i];
                if(!visited[v]){
                    pq.push({weight,v});
                }
            }
        }
        
        return sum;
    }
};