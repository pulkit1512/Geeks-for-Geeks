class Solution {
  public:
    int setBits(int n) {
        // Write Your Code here
        int count =0;
        for(int i=0;i<31;i++){
            count+=(n>>i)&1;
        }
        return count;
    }
};