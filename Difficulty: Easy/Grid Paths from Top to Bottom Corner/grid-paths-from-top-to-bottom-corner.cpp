class Solution {
  public:
    void dfs(vector<vector<int>>&mat,int n,int m,vector<vector<int>>&ans,vector<int>&temp,int i,int j){
        if(i==n||j==m) return ;
        temp.push_back(mat[i][j]);
        if(i==n-1&&j==m-1){
            ans.push_back(temp);
        }
        
        
        
        dfs(mat,n,m,ans,temp,i,j+1);
        dfs(mat,n,m,ans,temp,i+1,j);
        temp.pop_back();
    }
    vector<vector<int>> allPaths(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        
        int count=0;
        vector<vector<int>>ans;
        vector<int>temp;
        
        dfs(mat,n,m,ans,temp,0,0);
        return ans;
    }
};