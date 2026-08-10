int row[4]={-1,1,0,0};
int col[4]={0,0,-1,1};

class Solution {
  public:
    bool valid(int r,int c,int n,int m){
        return r>=0&&r<n&&c>=0&&c<m;
    }
    void dfs(vector<vector<int>>&mat,int n,int m,int i,int j){
        mat[i][j]=2;
        for(int k=0;k<4;k++){
            int r=i+row[k];
            int c=j+col[k];
            
            if(r>=0&&r<n&&c>=0&&c<m&&mat[r][c]==1){
                dfs(mat,n,m,r,c);            
            }
        }
    }
    
    int countGroups(vector<vector<int>>& mat) {
        // code here
        int n =mat.size();
        int m=mat[0].size();
        
        for(int j=0;j<m;j++){
            if(mat[0][j]==1){
                dfs(mat,n,m,0,j);
            }
            if(mat[n-1][j]==1){
                dfs(mat,n,m,n-1,j);
            }
        }
        for(int i=0;i<n;i++){
            if(mat[i][0]==1){
                dfs(mat,n,m,i,0);
            }
            if(mat[i][m-1]==1){
                dfs(mat,n,m,i,m-1);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    dfs(mat,n,m,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};