class Solution {
  public:
    bool helper(vector<int>arr,int k,int index,int sum){
        if(sum==k) return true;
        if(sum>k||index>=arr.size()) return false;
        return helper(arr,k,index+1,sum+arr[index])||helper(arr,k,index+1,sum);
    }
    bool checkSubsequenceSum(vector<int>& arr, int k) {
        // Code here
       return helper(arr,k,0,0);
    }
};