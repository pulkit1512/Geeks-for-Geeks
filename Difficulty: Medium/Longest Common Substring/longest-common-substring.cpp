class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
        // code here
        int n=s1.length(),m=s2.size();
        vector<int>dp(m+1,0);     
        int maxi=0;
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(s1[i-1]==s2[j-1]){
                    dp[j]=1+dp[j-1];
                    maxi=max(maxi,dp[j]);
                }
                else dp[j]=0;
            }
        }
        return maxi;
    }
};