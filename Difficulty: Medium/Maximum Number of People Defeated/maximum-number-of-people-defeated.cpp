class Solution {
  public:
    int maxPeopleDefeated(int p) {
        // Code Here
        int ans=0;
        int i=1;
        while(p>=i*i){
            p-=i*i;
            ans++;
            i++;
        }
        return ans;
    }
};
