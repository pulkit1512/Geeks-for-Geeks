class Solution {
  public:
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        // code here
        vector<vector<int>>ans(V);
        
        for(int i=0;i<edges.size();i++){
            ans[edges[i].first].push_back(edges[i].second);
            ans[edges[i].second].push_back(edges[i].first);
        }
        return ans;
    }
};