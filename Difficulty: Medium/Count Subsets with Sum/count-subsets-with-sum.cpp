class Solution {
  public:
    
    int  find(vector<int>&arr,int target,int index,vector<vector<int>>&dp){
        // if(target==0) return 1;
        if(index<0) return target==0;
        if(target<0) return 0;
        if(dp[index][target]!=-1) return dp[index][target];
        return dp[index][target]=find(arr,target-arr[index],index-1,dp)+find(arr,target,index-1,dp);
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n =arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return find(arr,target,n-1,dp);
    }
};