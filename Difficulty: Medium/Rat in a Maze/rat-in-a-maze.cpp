int row[] = {1, 0, 0, -1};
int col[] = {0, -1, 1, 0};
string dir = "DLRU";
class Solution {
	public:
	bool valid(int i,int j, int n ){
	    return i>=0&&j>=0&&i<=n-1&&j<=n-1;
	}
	void helper(vector<vector<int>> &maze, int i, int j, int n, string& path, vector<string>&ans,vector<vector<bool>> &visited) {
		if (i == n - 1 && j == n - 1) {
			ans.push_back(path);
			return ;
		}
		visited[i][j] = 1;
		for (int k = 0; k<4; k++) {
			if (valid(i + row[k], j + col[k], n) && maze[i + row[k]][j + col[k]] && !visited[i + row[k]][j + col[k]]) {
				path.push_back(dir[k]);
				helper(maze, i + row[k], j + col[k], n, path, ans,visited);
				path.pop_back();
			}
		}
		visited[i][j] = 0;
	}
	vector<string> ratInMaze(vector<vector<int>> & maze) {
		// code here
		int n = maze.size();
		vector<string>ans;
		if (n == 0 || maze[0][0] == 0 || maze[n - 1][n - 1] == 0) {
			return ans;
		}
		
		
		string path="";
		vector<vector<bool>> visited(n, vector<bool>(n, false));
		helper(maze, 0, 0, n,path, ans, visited);
		return ans;
	}
};
