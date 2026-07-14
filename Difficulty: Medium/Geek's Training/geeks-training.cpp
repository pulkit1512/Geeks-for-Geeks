class Solution {
public:
    int find(int x, int y, int m, vector<vector<int>> &mat, int prev, vector<vector<int>> &dp) {
        if (x >= m) return 0;
        if (y >= 3) return -1e9;
        
        if (dp[x][prev] != -1) return dp[x][prev];
        
        int first = -1e9;
        if (y != prev) {
            first = mat[x][y] + find(x + 1, 0, m, mat, y, dp);
        }
        
        int second = find(x, y + 1, m, mat, prev, dp);
        
        return dp[x][prev] = max(first, second);
    }
    
    int maximumPoints(vector<vector<int>> &mat) {
        int m = mat.size();
        vector<vector<int>> dp(m, vector<int>(4, -1));
        return find(0, 0, m, mat, 3, dp);
    }
};