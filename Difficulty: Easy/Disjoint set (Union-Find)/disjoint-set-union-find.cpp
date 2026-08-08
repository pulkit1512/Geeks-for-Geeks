class Solution {
  public:
    int find(int node,vector<int>&rep){
        if(rep[node]==node){
            return rep[node];
        }
        return rep[node]=find(rep[node],rep);
    }
    vector<int> DSU(int n, vector<vector<int>>& queries) {
        // code here
        vector<int>rep(n+1,0);
        for(int i=0;i<=n;i++){
            rep[i]=i;
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            if(queries[i][0]==2){
                ans.push_back(find(queries[i][1],rep));
            }
            if(queries[i][0]==1){
                int rep1=find(queries[i][1],rep);
                int rep2=find(queries[i][2],rep);
                rep[rep1]=rep[rep2];
            }
        }
        return ans;
    }
};