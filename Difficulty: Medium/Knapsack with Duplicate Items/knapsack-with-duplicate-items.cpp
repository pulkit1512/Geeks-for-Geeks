class Solution {
  public:
  
    // int find(vector<int>&val,vector<int>&wt,int index,int capacity,vector<vector<int>>&dp){
    //     if(capacity==0) return 0;
    //     if(index<0) return 0;
        
    //     if(dp[index][capacity]!=-1) return dp[index][capacity];
        
    //     if(wt[index]>capacity) return find(val,wt,index-1,capacity,dp);
        
    //     return max(val[index]+find(val,wt,index,capacity-wt[index],dp),find(val,wt,index-1,capacity,dp));
    // }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<vector<int>>dp(n+1,vector<int>(capacity+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=capacity;j++){
                if(wt[i-1]>j) dp[i][j]=dp[i-1][j];
                else dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
            }
        }
        return dp[n][capacity];
    }
};