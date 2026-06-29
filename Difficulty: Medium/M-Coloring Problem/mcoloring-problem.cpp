class Solution {
  public:
    bool find(int v,vector<vector<int>>&edges,int m,vector<int>&color,int node){
        if(node==v) return 1;
        for(int i=0;i<m;i++){
            //check if adjacent node has same color or not
            bool ispossible=1;
            for(int j=0;j<v;j++){
                if(edges[node][j]&&color[j]==i){
                    ispossible=0;
                    break;
                }
            }
            if(ispossible){
                color[node]=i;
                if(find(v,edges,m,color,node+1)) return 1;
                color[node]=-1;
            }
        }
        return 0;
    }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<int>color(v,-1);
        vector<vector<int>> matrix(v, vector<int>(v, 0));
        
        // 2. Populate the matrix using the input edge list
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int w = edges[i][1];
            matrix[u][w] = 1;
            matrix[w][u] = 1; // Since the graph is undirected
        }
        
        return find(v,matrix,m,color,0);
    }
};