class Solution {
  public:
     int findparent(int u,vector<int>&parent){
         if(u==parent[u]) return u;
         
         return parent[u]=findparent(parent[u],parent);
     }
     
     void unionrank(int u,int v,vector<int>&rank,vector<int>&parent){
         int pu=findparent(u,parent);
         int pv=findparent(v,parent);
         
         if(rank[pu]>rank[pv]) parent[pv]=pu;
         else if(rank[pu]<rank[pv]) parent[pu]=pv;
         else{
             parent[pv]=pu;
             rank[pu]++;
         }
     }
    
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>parent(V);
        vector<int>rank(V);
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            
            pq.push({wt,{u,v}});
        }
        int ans=0;
        while(!pq.empty()){
            auto [wt, p] = pq.top();
           
            int u = p.first;
            int v = p.second;
            pq.pop();
            if(findparent(u,parent)!=findparent(v,parent)){
                ans+=wt;
                unionrank(u,v,rank,parent);
                
            }
            
            
            
            
        }
        return ans;
    }
};