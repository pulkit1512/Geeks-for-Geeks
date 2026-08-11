int row[4]={-1,1,0,0};
int col[4]={0,0,-1,1};
class Solution {
	public:
	bool dfs(vector<vector<int>>&mat,int i,int j,int n,int m){
	    if(mat[i][j]==2) return 1;
	    
	    mat[i][j]=4;
	    
	    for(int k=0;k<4;k++){
	        int r=i+row[k];
	        int c=j+col[k];
	        
	        if(r>=0&&r<n&&c>=0&&c<m&&mat[r][c]!=0&&mat[r][c]!=4){
	            if(dfs(mat,r,c,n,m)) return 1;
	        }
	    }
	    
	    return 0;
	}
	bool isPathPossible(vector<vector<int>> & mat) {
		// code here
		int n = mat.size();
		int m = mat[0].size();
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<m; j++) {
				if(mat[i][j]==1){
				    if(dfs(mat,i,j,n,m)) return 1;
				}
			}
		}
		return 0;
	}
};
