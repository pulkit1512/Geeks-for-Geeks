int row[4]={-1,1,0,0};
int col[4]={0,0,-1,1};
class Solution {
	public:
	void dfs(vector<vector<int>> & image, int sr, int sc,int newColor,int n,int m,int x){
	     image[sr][sc]=newColor;
	     
	     for(int k=0;k<4;k++){
	         int r=sr+row[k];
	         int c=sc+col[k];
	         
	         if(r>=0&&r<n&&c>=0&&c<m&&image[r][c]==x){
	             dfs(image,r,c,newColor,n,m,x);
	         }
	     }
	}
	vector<vector<int>> floodFill(vector<vector<int>> & image, int sr, int sc,int newColor) {
		// code here
		int n = image.size();
		int m = image[0].size();
		if (image[sr][sc] == newColor) {
            return image;
        }
		dfs(image, sr, sc, newColor,n,m,image[sr][sc]);
		return image;
	}
};
