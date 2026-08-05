class Solution {
  public:
    int find(int i,int j,vector<int>&arr,vector<vector<int>>&dp){
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        int steps;
        for(int k=i;k<j;k++){
            steps=arr[i-1]*arr[k]*arr[j]+find(i,k,arr,dp)+find(k+1,j,arr,dp);
            mini=min(steps,mini);
        }
        return dp[i][j]=mini;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return find(1,n-1,arr,dp);
    }
};