int row[] = {-1, 1, 0, 0};
int col[] = {0, 0, -1, 1};

class Solution {
	public:
	
	bool valid(int i, int j, int n, int m) {
		return i >= 0 && i <= n - 1 && j >= 0 && j <= m - 1;
	}
	bool find(vector<vector<char>> &mat, string&word, string&temp, int i, int j, int n, int m, vector<vector<bool>> & visited) {
		if (temp != word.substr(0, temp.length()))
			return false;
		if (temp == word)
			return true;
		visited[i][j] = 1;
		for (int k = 0; k<4; k++) {
			if (valid(i + row[k], j + col[k], n, m) && !visited[i + row[k]][j + col[k]]) {
				temp.push_back(mat[i + row[k]][j + col[k]]);
				if (find(mat, word, temp, i + row[k], j + col[k], n, m, visited)) {
					return true;
				}
				temp.pop_back();
			}
		}
		visited[i][j] = 0;
		return false;
		
	}
	bool isWordExist(vector<vector<char>> &mat, string &word) {
		// Code here
		int n = mat.size();
		int m = mat[0].size();
		vector<vector<bool>>visited(n,vector<bool>(m, 0));
		
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<m; j++) {
				string temp = "";
				if (mat[i][j] == word[0]) {
					temp.push_back(mat[i][j]);
					if (find(mat, word, temp, i, j, n, m, visited))
						return true;
				}
			}
		}
		return false;
	}
};
