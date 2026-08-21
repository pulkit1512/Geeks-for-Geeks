class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        queue<tuple<int,int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==2){
                    q.push({i,j,0});
                }
            }
        }
        
        int ans=0;
        while(!q.empty()){
            auto [x,y,t]=q.front();
            q.pop();
            ans=t;
            int row[4]={-1,1,0,0};
            int col[4]={0,0,1,-1};
            
            for(int k=0;k<4;k++){
                int r=x+row[k];
                int c=y+col[k];
                if(r>=0&&r<n&&c>=0&&c<m&&mat[r][c]==1){
                    q.push({r,c,t+1});
                    mat[r][c]=2;
                    
                }
                
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    return -1;
                }
            }
        }
        return ans;
    }
};