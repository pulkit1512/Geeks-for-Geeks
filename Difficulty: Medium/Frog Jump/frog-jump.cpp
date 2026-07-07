class Solution {
	public:
	int helper(vector<int>& height, int index,vector<int>&dp) {
		if (index >= height.size() - 1) {
			return 0;
		}
		
		if(dp[index]!=-1) return dp[index];
		int jumpOne = helper(height, index + 1,dp) + abs(height[index] - height[index + 1]);
		
		int jumpTwo = INT_MAX;
		if (index + 2 < height.size()) {
			jumpTwo = helper(height, index + 2,dp) + abs(height[index] - height[index + 2]);
		}
		
		dp[index]=min(jumpOne,jumpTwo);
		return dp[index];
	}
	
	int minCost(vector<int>& height) {
	    int n=height.size();
	    vector<int>dp(n+1,-1);
		return helper(height, 0,dp);
	}
};
