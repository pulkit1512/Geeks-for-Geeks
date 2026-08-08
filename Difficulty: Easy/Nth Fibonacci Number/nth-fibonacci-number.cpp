class Solution {
  public:
  int  helper(int i){
        if(i<=1) return i;
        
        return helper(i-1)+helper(i-2);
        
    }
    int nthFibonacci(int n) {
        // code here
        return helper(n);
    }
};