class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        vector<int>temp;
        int i=0,j=n-1;
        while(i<j){
            temp.push_back(arr[i]);
            temp.push_back(arr[j]);
            i++;
            j--;
        }
        
        if (i == j) {
          temp.push_back(arr[i]);
        }
        long long  ans=0;
        i=0,j=1;
        while(j<n){
            ans+=abs(temp[i]-temp[j]);
            i++;
            j++;
        }
        ans+=abs(temp[0]-temp[n-1]);
        return ans;
    }
};
