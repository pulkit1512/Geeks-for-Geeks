class Solution {
  public:
  
    void dfs(vector<vector<int>>&grid,int i,int j,int n,int m,int &count){
        int row[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int col[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for(int k=0;k<8;k++){
            int r=i+row[k];
            int c=j+col[k];
            if(r>=0&&r<n&&c>=0&&c<m&&grid[r][c]==1){
                count++;
                grid[r][c]=0;
                dfs(grid,r,c,n,m,count);
            }
        }
    }
    int largestRegion(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count=0;
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    count=1;
                    dfs(grid,i,j,n,m,count);
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};                                                                                                                                  