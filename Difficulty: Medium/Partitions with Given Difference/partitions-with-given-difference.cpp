class Solution {
	public:
	
	int find(vector<int>&arr,int target){
	    int n=arr.size();
	    vector<vector<int>>dp(n+1,vector<int>(target+1,0));
	    for(int i=0;i<=n;i++){
	        dp[i][0]=1;
	    }
	    for(int i=1;i<=n;i++){
	        for(int j=0;j<=target;j++){
	            if(arr[i-1]>j) dp[i][j]=dp[i-1][j];
	            else dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
	        }
	    }
	    return dp[n][target];
	}
	int countPartitions(vector<int>& arr, int diff) {
		 int amount=0;
		 for(int i=0;i<arr.size();i++){
		     amount+=arr[i];
		 }
		 if((amount-diff)%2==0&&amount>=diff){
		     return find(arr,(amount-diff)/2);
		 }
		 return  0;
	}
};
