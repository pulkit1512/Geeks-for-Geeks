class Solution {
  public:
    //  void helper(int n ,int sourc,int help,int dest){
    //      if(n==1){
    //          cout<<"move disk"<< n <<"from rod"<<sourc<<"to rod"<<dest;
    //          return;
    //      }
    //      helper(n-1,sourc,dest,help);
    //      cout<<"move disk"<<n<<"from rod"<<sourc<<"to rod"<<dest;
    //      helper(n-1,help,sourc,dest);
         
         
    //  }
    int towerOfHanoi(int n, int from, int to, int aux) {
        // code here
        // helper(n,from,to,aux);
        return pow(2,n)-1;
    }
};