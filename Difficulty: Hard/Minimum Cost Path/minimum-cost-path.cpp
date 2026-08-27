

class Solution {
  public:
    // Function to return the minimum cost to react at bottom
    // right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) {
        int n = grid.size();
       vector<vector<int>>dist(n,vector<int>(n,1e8));
       priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
       pq.push({grid[0][0],0,0});
       dist[0][0]=grid[0][0];
       
       while(!pq.empty()){
           auto [w,x,y]=pq.top();
           pq.pop();
           
           int row[4]={-1,1,0,0};
           int col[4]={0,0,-1,1};
           
           for(int k=0;k<4;k++){
               int r=x+row[k];
               int c=y+col[k];
               if(r>=0&&r<n&&c>=0&&c<n){
                   if(dist[r][c]>grid[r][c]+w){
                       dist[r][c]=grid[r][c]+w;
                       pq.push({dist[r][c],r,c});
                   }
               }
           }
       }
       return dist[n-1][n-1];
        
    }
};