class Solution {
  public:
    bool helper(vector<int>&arr,int sum,int n,int index,int ans,vector<vector<int>>&dp){
        if(ans==sum) return 1;
        if(index>=n||ans>sum) return 0;
        if(dp[index][ans]!=-1) return dp[index][ans];
        return dp[index][ans] =(helper(arr,sum,n,index+1,ans+arr[index],dp)||helper(arr,sum,n,index+1,ans,dp));
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        int ans=0;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return helper(arr,sum,n,0,0,dp);
    }
};