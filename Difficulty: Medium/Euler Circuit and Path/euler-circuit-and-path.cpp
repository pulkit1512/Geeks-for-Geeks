class Solution {
  public:
    void dfs(vector<vector<int>>&adj,int node,vector<bool>&visited){
        visited[node]=1;
        for(int i=0;i<adj[node].size();i++){
            if(!visited[adj[node][i]]){
                dfs(adj,adj[node][i],visited);
            }
        }
    }
    int isEulerCircuit(int V, vector<vector<int>>& adj) {
        // code here
        vector<int>indeg(V,0);
        vector<bool>visited(V,0);
        int oddCount=0;
        for(int i=0;i<V;i++){
            indeg[i]=adj[i].size();
            if(indeg[i]%2!=0) oddCount++;
        }
        if(oddCount!=0&&oddCount!=2) return 0;
        
        for(int i=0;i<V;i++){
            if(indeg[i]){
                dfs(adj,i,visited);
                break;
            }
        }
        
        for(int i=0;i<V;i++){
            if(indeg[i]&&!visited[i]) return 0;
        }
        
        if(oddCount==0){
            return 2;
        }
        else{
            return 1;
        }
    }
};