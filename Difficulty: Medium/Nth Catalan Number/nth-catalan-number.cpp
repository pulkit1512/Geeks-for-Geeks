class Solution {
  public:
    // Function to find the nth catalan number.
    
    int find(int n,int i,int j,vector<vector<int>>&dp){
        if(i==n&&j==n) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int x1=0,x2=0;
        
        if(i<n) x1=find(n,i+1,j,dp);
        if(i>j) x2=find(n,i,j+1,dp);
        
        return dp[i][j]=x1+x2;
    }
    int findCatalan(int n) {
        // code here
        if(n==0) return 1;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return find(n,1,0,dp);
    }
};