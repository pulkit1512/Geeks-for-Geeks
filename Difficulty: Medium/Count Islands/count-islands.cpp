int row[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int col[8] = {1, 0, -1, 0, -1, 1, 1, -1};
class Solution {
	public:
	bool valid(int a,int b,int n,int m){
	    return a>=0&&a<n&&b>=0&&b<m;
	}
	void dfs(vector<vector<char>>&grid,int i,int j,int n,int m) {
		grid[i][j]='V';
		
		for(int k=0;k<8;k++){
		    int r=i+row[k];
		    int c=j+col[k];
		    if(valid(r,c,n,m)&&grid[r][c]=='L'){
		        dfs(grid,r,c,n,m);
		    }
		}
	}	
	int countIslands(vector<vector<char>> & grid) {
		// Code here
		int n = grid.size();
		int m = grid[0].size();
		int count = 0;
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<m; j++) {
				if (grid[i][j] == 'L') {
					dfs(grid, i, j, n, m);
					count++;
				}
			}
		}
		return count;
	}
};
