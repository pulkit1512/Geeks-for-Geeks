class Solution {
  public:
    // Function to return list containing first n fibonacci numbers.
    int  helper(int i){
        if(i<=1) return i;
        
        return helper(i-1)+helper(i-2);
        
    }
    vector<int> fibonacciNumbers(int n) {
        // code here
        vector<int>ans;
        for(int i=0;i<n;i++){
            int x=helper(i);
            ans.push_back(x);
        }
        return ans;
    }
};