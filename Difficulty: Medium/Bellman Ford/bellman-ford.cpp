class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>dist(V,1e8);
        dist[src]=0;
        for(int i=0;i<V-1;i++){
            bool flag=0;
            for(int i=0;i<edges.size();i++){
                
                int u=edges[i][0];
                int v=edges[i][1];
                int weight=edges[i][2];
                if(dist[u]==1e8) continue;
                if(dist[u]+weight<dist[v]){
                    flag=1;
                    dist[v]=dist[u]+weight;
                }
            }
            if(!flag) return dist;
        }
        for(int i=0;i<edges.size();i++){
                int u=edges[i][0];
                int v=edges[i][1];
                int weight=edges[i][2];
                if(dist[u]+weight<dist[v]){
                    vector<int>ans;
                    ans.push_back(-1);
                    return ans;
            }
        }
        return dist;
    }
};
