int row[4]={-1,1,0,0};
int col[4]={0,0,-1,1};
class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat, vector<int> &src, vector<int> &dest) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        int posx=src[0];
        int posy=src[1];
        int targetx=dest[0];
        int targety=dest[1];
        if(mat[posx][posy]==0||mat[targetx][targety]==0) return -1;
        queue<tuple<int,int,int>>q;
        q.push({posx,posy,0});
        mat[posx][posy]=2;
        while(!q.empty()){
            auto [x,y,c]=q.front();
            q.pop();
            if(x==targetx&&y==targety) return c;
            for(int i=0;i<4;i++){
                int r=x+row[i];
                int z=y+col[i];
                if(r>=0&&r<n&&z>=0&&z<m&&mat[r][z]==1){
                    q.push({r,z,c+1});
                    mat[r][z]=2;
                }
            }
        }
        return -1;
    }
};
